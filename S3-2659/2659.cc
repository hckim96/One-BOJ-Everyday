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

  tuple<int, int, int, int> cur;
  auto& [a,b,c,d] = cur;
  cin >> a >> b >> c >> d;

  auto getClock = [&](vi& v) {
    tuple<int, int, int, int> ret = {1e9, 1e9, 1e9, 1e9};
    for (int i = 0; i < 4; ++i) {
      tuple<int, int, int, int> tmp = {v[i], v[(i + 1) % 4], v[(i + 2) % 4], v[(i + 3) % 4]};
      ret = min(ret, tmp);
    }
    return ret;
  };

  set<tuple<int, int, int, int> > tmp;
  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      for (int k = 1; k < 10; ++k) {
        for (int l = 1; l < 10; ++l) {
          vi v = {i, j, k, l};
          tuple<int, int, int, int> tt = {i, j, k, l};
          auto c = getClock(v);
          if (tt == cur) {
            cur = c;
          }
          tmp.insert(c);
        }
      }
    }
  }
  int ans = 1;
  for (auto e: tmp) {
    if (e == cur) {
      cout << ans;
      break;
    }
    ++ans;
  }
}