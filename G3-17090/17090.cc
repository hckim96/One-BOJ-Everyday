#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  

  int n, m;
  cin >> n >> m;
  vvi ans(n, vi(m, 0));
  vvi vis(n, vi(m, 0));

  vector<string> v(n);
  each(e, v) cin >> e;

  
  function<int(int, int)> f = [&](int i, int j) {

    if (i < 0 || i >= n || j < 0 || j >= m) return 1;
    if (vis[i][j]) return ans[i][j];
    vis[i][j] = true;
    if (ans[i][j]) return 1;
    
    int dir;
    switch (v[i][j]) {
      case 'R': dir = 0; break;
      case 'L': dir = 1; break;
      case 'D': dir = 2; break;
      case 'U': dir = 3; break;
    }
    int ni = i + dr[dir];
    int nj = j + dc[dir];
    return ans[i][j] = f(ni, nj);
  };
  FOR(i, 0, n) FOR(j, 0, m) {
    if (ans[i][j]) continue;
    f(i, j);
  }
  int sum = 0;
  each(e, ans) each(ee, e) sum += ee;
  cout << sum;
}