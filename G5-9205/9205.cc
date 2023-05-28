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

  int TC; cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n + 2);
    each(e, v) cin >> e.first >> e.second;


    // 맥주 개수, 안먹고 더 갈수있는 거리, idx
    queue<tuple<int, int, int> > q;
    q.push({20, 0, 0});
    set<tuple<int, int, int> > vis;
    vis.insert({20, 0, 0});
    while (q.size()) {
      auto [fb, fd, fn] = q.front();
      q.pop();
      if (fn == n + 1) {
        cout << "happy\n";
        goto here;
      }

      for (int i = 1; i < v.size(); ++i) {
        if (i == fn) continue;
        int tmp = abs(v[i].first - v[fn].first) + abs(v[i].second - v[fn].second);
        if (fb * 50 + fd < tmp) continue;
        
        int distBeer = tmp - fd;
        int nb = distBeer / 50 + (distBeer % 50 != 0);
        int nd = (distBeer % 50 != 0 ? 50 - distBeer % 50 : 0);
        assert(nb <= 20);
        if (i != n) {
          nb = 20;
        }
        if (vis.count({nb, nd, i})) continue;
        vis.insert({nb, nd, i});
        q.push({nb, nd, i});
      }
    }
    cout << "sad\n";
    here:;
  }
}