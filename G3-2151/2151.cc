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

  pair<int, int> start = {-1, 0}, end = {0, 0};

  int n;
  cin >> n;
  vector<string> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    for (int j = 0; j < n; ++j) {
      if (v[i][j] == '#') {
        if (start.first == -1) {
          start = {i, j};
        } else {
          end = {i, j};
        }
      }
    }
  }

  int ans = 1e9;

  queue<tuple<int, int, int, int> > q;
  set<tuple<int, int, int, int> > vis;
  for (int d = 0; d < 4; ++d) {
    q.push({d, start.first, start.second, 0});
    vis.insert({d, start.first, start.second, 0});
  }

  while (q.size()) {
    auto [fd, fr, fc, fcnt] = q.front();
    q.pop();
    if (fr == end.first && fc == end.second) {
      ans = min(ans, fcnt);
      continue;
    }
    if (fcnt >= ans) continue;

    if (v[fr][fc] == '!') {
      for (int nd = 0; nd < 4; ++nd) {
        if (nd + fd == 1 || nd + fd == 5) continue;
        int nr = fr + dr[nd];
        int nc = fc + dc[nd];
        int ncnt = (fd != nd) + fcnt;
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (v[nr][nc] == '*') continue;
        if (vis.count({nd, nr, nc, ncnt})) continue;
        q.push({nd, nr, nc, ncnt});
        vis.insert({nd, nr, nc, ncnt});
      }
    } else {
      int nr = fr + dr[fd];
      int nc = fc + dc[fd];
      int nd = fd;
      int ncnt = fcnt;
      if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
      if (v[nr][nc] == '*') continue;
      if (vis.count({nd, nr, nc, ncnt})) continue;
      q.push({nd, nr, nc, ncnt});
      vis.insert({nd, nr, nc, ncnt});
    }
  }
  cout << ans;
}