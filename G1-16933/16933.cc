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

  int n, m, k;
  cin >> n >> m >> k;

  vs v(n);
  each(e, v) cin >> e;

  queue<tuple<int, int, int> > q;
  
  // k, r, c
  vector<vvi> vis(k + 1, vvi(n, vi(m)));

  q.push({0, 0, 0});
  vis[0][0][0] = true;
  int ans = 0;
  while (q.size()) {
    ++ans;
    int tmp = q.size();
    while (tmp--) {
      auto [fk, fr, fc] = q.front();
      int isDay = ans % 2;
      q.pop();
      if (fr == n - 1 && fc == m - 1) {
        cout << ans;
        return 0;
      }

      for (int dir = 0; dir < 4; ++dir) {
        int nr = fr + dr[dir];
        int nc = fc + dc[dir];
        int nk = fk;

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (vis[nk][nr][nc]) continue;
        if (v[nr][nc] == '1') {
          if (!isDay || fk == k) continue;
          nk++;
        }
        vis[nk][nr][nc] = true;
        q.push({nk, nr, nc});
      }

      // not move
      if (!isDay && vis[fk][fr][fc] != 2) {
        vis[fk][fr][fc] = 2;
        q.push({fk, fr, fc});
      }
    }
  }

  cout << -1;
}