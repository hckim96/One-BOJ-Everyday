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

  ll n, l, r;
  cin >> n >> l >> r;
  vl v(n);
  each(e, v) cin >> e;

  ll ansR = 0;
  ll ansL = 0;
  function<void(int, ll, int)> f = [&] (int cur, ll tmp, int cnt) {
    if (tmp > r) return;

    if (cur == n) {
      if (cnt > 0) {
        ll flag = (cnt % 2 ? 1 : -1);
        ansR += flag * (r / tmp);
        ansL += flag * ((l - 1) / tmp);
      }
      return;
    }

    f(cur + 1, tmp, cnt);
    f(cur + 1, tmp / gcd(tmp, v[cur]) * v[cur], cnt + 1);
  };

  f(0, 1, 0);
  cout << ansR - ansL;
}