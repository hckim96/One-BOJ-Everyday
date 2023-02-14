#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int r, c;
  cin >> r >> c;
  
  vector<string> v(r);
  for (auto& e: v) cin >> e;


  vector<vector<int> > visited(r, vector<int> (c,0));

  int ans1 = 0;
  int ans2 = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (visited[i][j]) continue;
      if (v[i][j] == '#') continue;

      int sheep = 0;
      int wolf = 0;

      queue<pair<int, int> > q;
      int dr[4] = {0, 0, 1, -1};
      int dc[4] = {1, -1, 0, 0};
      q.push({i, j});
      visited[i][j] = true;
      while (q.size()) {
        auto [fr, fc] = q.front();
        q.pop();
        if (v[fr][fc] == 'v') {
          wolf++;
        } else if (v[fr][fc] == 'o') {
          sheep++;
        }

        for (int dir = 0; dir < 4; ++dir) {
          int nr = fr + dr[dir];
          int nc = fc + dc[dir];
          if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
          if (visited[nr][nc]) continue;
          if (v[nr][nc] == '#') continue;

          
          
          visited[nr][nc] = true;
          q.push({nr, nc});
        }
      }

      if (sheep > wolf) {
        ans1 += sheep;
      } else {
        ans2 += wolf;
      }
    }
  }
  cout << ans1 << ' ' << ans2 << '\n';
  
}