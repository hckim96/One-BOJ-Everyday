#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N;
  cin >> N;

  vector<string> v(N);
  for (auto& e: v) cin >> e;

  int dr[4] = {0, 0, 1, -1};
  int dc[4] = {1, -1, 0, 0};
  int ans = 0;
  auto check = [&]() {

    for (int i = 0; i < N; ++i) {
      int cnt = 0;
      char prev = 'x';
      for (int j = 0; j < N; ++j) {
        if (v[i][j] != prev) cnt = 1;
        else ++cnt;
        ans = max(ans, cnt);
        prev = v[i][j];
      }
    }
    for (int i = 0; i < N; ++i) {
      int cnt = 0;
      char prev = 'x';
      for (int j = 0; j < N; ++j) {
        if (v[j][i] != prev) cnt = 1;
        else ++cnt;
        ans = max(ans, cnt);
        prev = v[j][i];
      }
    }

  };
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int dir = 0; dir < 4; ++dir) {
        int nr = i + dr[dir];
        int nc = j + dc[dir];
        if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
        if (v[nr][nc] == v[i][j]) continue;

        swap(v[nr][nc], v[i][j]);
        check();
        swap(v[nr][nc], v[i][j]);
      }
    }
  }
  cout << ans << '\n';
}