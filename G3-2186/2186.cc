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
typedef vector<string> vs;
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

  int n, m, k;
  cin >> n >> m >> k;

  vs v(n);
  each(e,v) cin >> e;

  string target;
  cin >> target;

  vector<vvi> dp(target.size(), vvi(n, vi(m, -1)));

  function<int(int, int, int)> f = [&](int cur, int r, int c) {
    if (cur == target.size() - 1) {
      return 1;
    }
    auto& ret = dp[cur][r][c];
    if (ret != -1) return ret;

    ret = 0;
    for (int kk = 1; kk <= k; ++kk) {
      for (int dir = 0; dir < 4; ++dir) {
        int rr = r + kk * dr[dir];
        int cc = c + kk * dc[dir];
        if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
        if (v[rr][cc] != target[cur + 1]) continue;
        ret += f(cur + 1, rr, cc);
      }
    }
    return ret;
  };

  int ans = 0;

  FOR(i, 0, n) FOR(j, 0, m) if (v[i][j] == target.front()) ans += f(0, i, j);

  cout << ans;
}