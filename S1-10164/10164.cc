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

  ll n, m, k;
  cin >> n >> m >> k;

  ll ans = 0;

  // a + b !  / a ! / b !
  auto f = [&](ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return 1LL;
    ll n = a + b;
    ll r = a;

    ll ret = 1L;
    for (ll i = 1; i <= a; ++i) {
      ret *= (n + 1 - i);
      ret /= i;
    }
    return ret;
  };

  if (k == 0) {
    cout << f(n - 1, m - 1) << '\n';
  } else {
    --k;
    ll r = k / m;
    ll c = k % m;
    cout << f(r, c) * f(n - 1 - r, m - 1 - c) << '\n';
  }
}