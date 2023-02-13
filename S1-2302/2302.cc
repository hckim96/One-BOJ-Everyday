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

  // l, 
    // 2, 0 -> 1, 2, 1 -> 1 
    // 3, 0 -> 2,0 + 2,1 , 3,1 -> 2,0   ... 2  1 
  vvl dp(41, vl(2, 0));
  dp[2][0] = 1;
  dp[2][1] = 1;
  for (int i = 3; i <= 40; ++i) {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    dp[i][1] = dp[i - 1][0];
  }
  auto f = [&](int n) {
    if (n == 0) return 1LL;
    if (n == 1) return 1LL;
    return dp[n][0] + dp[n][1];
  };

  ll n;
  cin >> n;
  ll m;
  cin >> m;
  ll prev = 0;
  ll ans = 1;
  while (m--) {
    ll num;
    cin >> num;
    ans *= f(num - prev - 1);
    prev = num;
  }
  ans *= f(n - prev);
  cout << ans;
}