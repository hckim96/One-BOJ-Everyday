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

  int k;
  cin >> k;

  int n = (1 << (k + 1)) - 1;
  vector<vector<pair<int, int> > > adj(n + 1);
  vi edge(n);
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    cin >> edge[i];
    ans += edge[i];
  }

  vi dp(n + 1, -1);
  function<int(int)> f = [&](int cur) {
    if (cur > n) return 0;
    auto& ret = dp[cur];
    if (ret != -1) return ret;

    int left = f(2 * cur);
    int right = f(2 * cur +  1);
    int le = (cur > n - (1 << k)) ? 0 : edge[2 * cur - 1];
    int re = (cur > n - (1 << k)) ? 0 : edge[2 * cur];

    ans += abs(left + le - (right + re));
    return ret = max(left + le, right + re);
  };
  f(1);
  cout << ans;
}