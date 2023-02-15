#include <bits/stdc++.h>

using namespace std;

int main() {
  int C, R;
  cin >> C >> R;

  int K;
  cin >> K;

  if (K > C * R) {
    cout << 0;
    return 0;
  }

  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  int x = 1;
  int y = 0;
  int dir = 0;
  vector<vector<int> > visited(C + 1, vector<int> (R + 1, 0));
  while (K--) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if (nx <= 0 || nx > C || ny <= 0 || ny > R || visited[nx][ny]) {
      dir += 1;
      dir %= 4;
      nx = x + dx[dir];
      ny = y + dy[dir];
    }
    x = nx;
    y = ny;
    visited[x][y] = 1;
  }
  cout << x << ' ' << y;
}