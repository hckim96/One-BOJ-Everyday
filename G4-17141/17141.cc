#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N, M;
  cin >> N >> M;

  vector<pair<int, int> > can;
  vector<vector<int> > orgv(N, vector<int> (N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> orgv[i][j];
      if (orgv[i][j] == 2) {
        can.push_back({i, j});
      }
    }
  }

  int ans = -1;
  auto check = [&](vector<vector<int> >& v) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (v[i][j] == 0 || v[i][j] == 2) {
          return false;
        }
      }
    }
    return true;
  };

  auto simul = [&](vector<int>& selected) {
    queue<pair<int, int> > q;
    auto v = orgv;
    for (int i = 0; i < selected.size(); ++i) {
      if (selected[i]) {
        v[can[i].first][can[i].second] = 3;
        q.push(can[i]);
      } else {
        v[can[i].first][can[i].second] = 0;
      }
    }
    int time = 0;
    while (q.size()) {
      if (check(v)) {
        if (ans == -1) {
          ans = time;
        } else {
          ans = min(ans, time);
        }
        return;
      }
      int tmp = q.size();
      int dr[4] = {0, 0, 1, -1};
      int dc[4] = {1, -1, 0, 0};
      while (tmp--) {
        auto [fr, fc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
          int nr = fr + dr[dir];
          int nc = fc + dc[dir];
          if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
          if (v[nr][nc] == 1) continue;
          if (v[nr][nc] == 3) continue;
          v[nr][nc] = 3;
          q.push({nr, nc});
        }
      }
      time++;
    }
  };

  vector<int> selected(can.size(), 0);
  function<void(int, int)> f = [&](int cur, int cnt) {
    if (cnt == 0) {
      simul(selected);
      return;
    }
    if (cur == selected.size()) return;

    f(cur + 1, cnt);
    selected[cur] = true;
    f(cur + 1, cnt - 1);
    selected[cur] = false;

  };

  f(0, M);
  cout << ans << '\n';
}