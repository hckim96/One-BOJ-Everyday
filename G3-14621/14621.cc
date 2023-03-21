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

  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int> > v(m);
  vi g(n + 1);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == 'W') g[i + 1] = 1;
  }
  for (auto& [a, b, c]: v) {
    cin >> b >> c >> a;
  }

  sort(all(v));
  vi p(n + 1, -1);
  function<int(int)> f = [&](int n) {
    if (p[n] == -1) return n;
    return p[n] = f(p[n]);
  };
  auto u = [&](int n1, int n2) {
    int p1 = f(n1);
    int p2 = f(n2);
    if (p1 == p2) return false;
    p[p1] = p2;
    return true;
  };
  int ans = 0;
  int cnt = 0;
  for (auto [c, a, b]: v) {
    if (g[a] != g[b] && u(a, b)) {
      ans += c;
      cnt++;
    }
  }

  if (cnt == n - 1) {
    cout << ans;
  } else {
    cout << -1;
  }
}