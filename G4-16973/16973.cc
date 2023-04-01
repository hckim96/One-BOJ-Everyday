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
  vvi v(n, vi(m));

  queue<pair<int, int> > qq;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
      if (v[i][j]) {
        qq.push({i, j});
      }
    }
  }

  int h, w, sr, sc, fr, fc;
  cin >> h >> w >> sr >> sc >> fr >> fc;
  sr--;
  sc--;
  fr--;
  fc--;
  while (qq.size()) {
    auto [r, c] = qq.front();
    qq.pop();
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        int rr = r - i;
        int cc = c - j;
        if (rr < 0 || rr >= n || cc < 0 || cc >= m) continue;
        v[rr][cc] = 1;
      }
    }
  }

  queue<pair<int, int> > q;
  vvi vis(n, vi(m));
  q.push({sr, sc});
  vis[sr][sc] = true;
  int ans = 0;

  while (q.size()) {
    int tmp = q.size();
    while (tmp--) {
      auto [r, c] = q.front();
      q.pop();
      if (r == fr && c == fc) {
        cout << ans << '\n';
        return 0;
      }
      for (int dir = 0; dir < 4; ++dir) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (vis[nr][nc]) continue;
        if (v[nr][nc]) continue;
        int nr2 = nr + h - 1;
        int nc2 = nc + w - 1;
        if (nr2 < 0 || nr2 >= n || nc2 < 0 || nc2 >= m) continue;

        q.push({nr, nc});
        vis[nr][nc] = true;
      }
    }
    ++ans;
  }

  cout << -1 << '\n';
}
