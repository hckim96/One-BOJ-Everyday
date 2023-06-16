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
typedef pair<ld, ld> pld;
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
  
  auto ccw = [&](pld& p1, pld& p2, pld& p3) {
    ld s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1; 
  };

  auto f = [&](pld& p1, pld& p2, pld& p3, pld& p4) {
    auto p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); 
    auto p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); 

    // one line
    if (p1p2 == 0 && p3p4 == 0) {
      if (p1 > p2) swap(p1, p2);
      if (p3 > p4) swap(p3, p4);
      return p3 <= p2 && p1 <= p4; // intersect?
    }
    return p1p2 <= 0 && p3p4 <= 0;
  };

  int n;
  cin >> n;

  vector<tuple<ll, pld, pld> > line(n);

  for (int i = 0;  i < n; ++i) {
    auto& [a,b,c] = line[i];
    cin >> b.first >> b.second >> c.first >> c.second >> a;
  }
  sort(all(line));

  ll ans = 0;
  FOR(i, 0, n) {
    auto [w1, a, b] = line[i];
    ans += w1;
    FOR(j, i + 1, n) {
      auto [w2, c, d] = line[j];
      if (f(a, b, c, d)) ans += w1;
    }
  }
  cout << ans;
}
