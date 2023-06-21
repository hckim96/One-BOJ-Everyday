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

  int q;
  cin >> q;
  vector<tuple<ll, ll, ll> > query(q);
  vector<tuple<ll, ll, ll> > queryOrg(q);
  vector<pair<ld, int> > v(q);
  for (int i = 0; i < q; ++i) {
    auto& [a, b, c] = query[i];
    cin >> a;
    if (a == 1) {
      cin >> b >> c;
      if (b == 0) {
        v[i] = {1.0L * 1e30, -1};
      } else {
        v[i] = {-1.0L * c / b,i};
      }
    } else {
      cin >> b;
      v[i] = {b, i};
    }
    queryOrg[i] = query[i];
  }
  sort(all(v));

  ld prev;
  int idx = 1;
  for (int i = 0; i < q; ++i) {
    if (v[i].second == -1) continue;
    auto& [a, b, c] = query[v[i].second];

    if (a == 1) {
      if (b > 0) b = 1;
      else if (b == 0) b = 0;
      else b = -1;

      if (i && abs(prev - v[i].first) > 1e-25) {
        c = ++idx;
      } else {
        c = idx;
      }
    } else {
      if (i && abs(prev - v[i].first) > 1e-25) {
        b = ++idx;
      } else {
        b = idx;
      }
    }
    prev = v[i].first;
  }

  vi t(2 * q);
  auto update = [&](int p, int v) {
    for (t[p += q] = v; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  };
  auto sum = [&](int l, int r) {
    int ret = 0;
    for (l += q, r += q; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret += t[l++];
      if (r & 1) ret += t[--r];
    }
    return ret;
  };

  int x = 0;
  int sign = 0;
  int allzero = false;
  for (int i = 0; i < q; ++i) {
    auto [a, b, c] = query[i];
    if (a == 1) {

      if (b == 0) {
        if (get<2>(queryOrg[i]) == 0) allzero = true;
        else {
          if (get<2>(queryOrg[i]) < 0) sign ^= 1;
        }
      } else {
        if (get<1>(queryOrg[i]) < 0) sign ^= 1;
        ++x;
        update(c, t[q + c] + 1);
      }
    } else {

      if (t[q + b] || allzero) cout << 0 << '\n';
      else cout << (((sign + x + sum(1, b + 1)) % 2 == 1) ? '-' : '+' )<< '\n';
    }
  }
}