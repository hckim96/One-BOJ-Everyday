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

  int r, c;
  int a, b;
  cin >> r >> c >> a >> b;
  vvi ans(r * a, vi (c * b));

  FOR(i, 0, r) FOR(j, 0, c) {
    if ((i + j) % 2 == 0) continue;
    FOR(k, 0, a) FOR(l, 0, b) {
      int rr = i * a + k;
      int cc = j * b + l;
      ans[rr][cc] = 1;
    }
  }

  FOR(i, 0, ans.size()) {
    FOR(j, 0, ans[0].size()) {
      cout << (ans[i][j] ? '.' : 'X');
    }
    cout << '\n';
  }
}