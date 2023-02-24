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

  int n,m ;
  cin >> n >> m;
  vvi v(n, vi(m));
  each(e, v) each(ee, e) cin >> ee;

  int ans = 0;
  int ans2 = 0;
  vvi vis(n, vi(m));
  for (int i = 0; i < n; ++i ) {
    for (int j = 0; j < m; ++j) {

      if (vis[i][j]) continue;
      if (v[i][j] == 0) continue;

  ++ans;
      queue<pair<int, int> > q;
      q.push({i, j});
      vis[i][j] = true;
      int tmp  = 1;
      ans2 = max(tmp, ans2);
      while (q.size()) {
        auto [fr, fc]  = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
          int nr = fr + dr[dir];
          int nc = fc  + dc[ dir];
          if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
          if (vis[nr][nc])continue;
          if (v[nr][nc] == 0) continue;

          q.push({nr, nc});
      ans2 = max(++tmp, ans2);
          vis[nr][nc] = true;
        }

      }
    }

  }

  cout << ans << '\n' << ans2;

}