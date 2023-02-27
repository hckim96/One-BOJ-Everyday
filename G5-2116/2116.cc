#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<int>> vvi;
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

  int n;
  cin >> n;

  vvi v(n, vi(6));
  vvi pos(n, vi(7));

  FOR(i, 0, n) {
    FOR(j, 0, 6) {
      cin >> v[i][j];
      pos[i][v[i][j]] = j;
    }
  }

  vi cross(6);
  cross[0] = 5;
  cross[5] = 0;
  cross[1] = 3;
  cross[3] = 1;
  cross[2] = 4;
  cross[4] = 2;

  ll ans = 0;
  FOR(i, 0, 6) {
    ll tmp = 0;

    int curi = i;
    int cur = 0;

    while (cur < n) {
      
      if (v[cur][curi] != 6 && v[cur][cross[curi]] != 6) tmp += 6;
      else if (v[cur][curi] != 5 && v[cur][cross[curi]] != 5) tmp += 5;
      else if (v[cur][curi] != 4 && v[cur][cross[curi]] != 4) tmp += 4;
      
      if (cur == n - 1) break;

      curi = pos[cur + 1][v[cur][cross[curi]]];
      ++cur;
    }
    ans = max(ans, tmp);
  }
  cout << ans;

}