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

  int n;
  cin >> n;
  vl y(n), d(n);
  each(e, y) cin >> e;
  each(e, d) cin >> e;
  int h = n / 2;
  
  auto check =  [&](ll k) {
    ll ret = 0;
    for (ll i = 0; i < n; ++i) {
      ret += abs(y[i] - (k + abs(i - h)));
      ret += abs(d[i] - (k + abs(i - h)));
    }
    return ret;
  };

  ll l = 0;
  ll r = 1e13;
  while (l + 2 < r) {
    ll p1 = (2 * l + r) / 3;
    ll p2 = (l + 2 * r) / 3;
    if (check(p1) <= check(p2)) {
      r = p2;
    } else { 
      l = p1;
    }
  }
  cout << min(check(l), check(l + 1));
}