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

  int N;
  cin >> N;
  int atk;
  cin >> atk;

  vector<tuple<int, int, int> > v(N);
  for (auto& [t, a, h]: v) {
    cin >> t >> a >> h;
  }

  ll l = 0;
  ll r = 1e18;

  auto check = [&](ll x) {
    ll t_atk = atk;
    ll t_cur = x;

    for (auto [t, a, h]: v) {
      if (t == 2) {
        t_atk += a;
        t_cur = min(t_cur + h, x);
      } else {
        ll cnt = h / t_atk + (h % t_atk > 0);
        t_cur -= (cnt - 1) * a;
        if (t_cur <= 0) return false;
      }
    }

    return true;
  };

  while (l + 1 < r) {
    ll mid = l + r >> 1;
    if (!check(mid)) l = mid;
    else r = mid;
  }

  cout << r << '\n';
}