#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
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

  ll n, m;
  cin >> n >> m;
  vvl v(n, vl(m));
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      v[i][j] = s[j] - '0';
    }
  }

  ll ans = 0;

  auto f = [&](int r1, int r2, int c1, int c2) {
    ll ret = 0;
    for (int i = r1; i <= r2; ++i) {
      for (int j = c1; j <= c2; ++j) {
        ret += v[i][j];
      }
    }
    return ret;
  };
  
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ll tmp = 1;
      tmp *= f(0, i, 0, m - 1);
      tmp *= f(i + 1, j, 0, m - 1);
      tmp *= f(j + 1, n - 1, 0, m - 1);
      ans = max(ans, tmp);
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      ll tmp = 1;
      tmp *= f(0, n - 1, 0, i);
      tmp *= f(0, n - 1, i + 1, j);
      tmp *= f(0, n - 1, j + 1, m - 1);
      ans = max(ans, tmp);
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i + 1 >= n || j + 1 >= m) continue;

      // up
      ans = max(ans,
        f(0, i, 0, m - 1)
        * f(i + 1, n - 1, 0, j)
        * f(i + 1, n - 1, j + 1, m - 1)
      );

      // left
      ans = max(ans,
        f(0,  n - 1, 0, j)
        * f(0, i, j + 1, m - 1)
        * f(i + 1, n - 1, j + 1, m - 1)
      );

      // down
      ans = max(ans,
        f(0,  i, 0, j)
        * f(0, i, j + 1, m - 1)
        * f(i + 1, n - 1, 0, m - 1)
      );
      // right
      ans = max(ans,
        f(0,  i, 0, j)
        * f(i + 1, n - 1, 0, j)
        * f(0, n - 1, j + 1, m - 1)
      );
    }
  }

  cout << ans << '\n';

}