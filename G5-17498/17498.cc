#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> tl;
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

  int n, m, d;
  cin >> n >> m >> d;
  vvi a(n, vi(m));
  each(e, a) each(ee, e) cin >> ee;

  vvi dp(n, vi(m, -2e9));
  for (int j = 0; j < m; ++j) dp[0][j] = 0;


  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int ii = 1; ii <= min(i, d) ; ++ii) {
        for (int jj = max(0, j - (d - ii)); jj <= min(m - 1, j + (d - ii)); ++jj) {
          dp[i][j] = max(dp[i][j], dp[i - ii][jj] + a[i - ii][jj] * a[i][j]);
        }
      }
    }
  }
  
  int ans = -2e9;
  for (int j = 0; j < m; ++j) ans = max(ans, dp[n - 1][j]);
  cout << ans;
}