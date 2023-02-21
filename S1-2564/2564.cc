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

  int C, R;
  cin >> C >> R;

  int n;
  cin >> n;
  vector<pair<int, int> > v(n + 1);
  each(e, v) cin >> e.first >> e.second;

  int ans = 0;
  auto calc = [&](pair<int, int> p1, pair<int ,int> p2) {
    if (p1.first > p2.first) swap(p1, p2);
    auto [a, x] = p1;
    auto [b, y] = p2;
    if (a == 1) {
      if (b == 1) return abs(x - y);
      if (b == 2) return  R + min(x + y, 2 * C - x - y);
      if (b == 3) return x + y;
      if (b == 4) return C - x + y;
    }
    if (a == 2) {
      if (b == 2) return abs(x - y);
      if (b == 3) return x  + R - y;
      if (b == 4) return R + C - x - y;
    }
    if (a == 3) {
      if (b == 3) return abs(x - y);
      if (b == 4) return C + min(x + y, 2 * R - x- y);
    }
    if (a == 4) {
      if (b == 4) return abs(x - y);
    }
  };

  for (int i = 0; i < n; ++i) {
    ans += calc(v[i], v[n]);
  }
  cout << ans << '\n';
}