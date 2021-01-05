#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 50

int T, N, M, K;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {

        cin >> M >> N >> K;

        int map[N_MAX][N_MAX] = {0};
        bool visited[N_MAX][N_MAX] = {0};
        int cnt = 0;

        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    cnt++;

                    // bfs
                    queue<pair<int, int> > q;
                    q.push({i, j});
                    visited[i][j] = true;

                    while (!q.empty()) {
                        auto [fr, fc] = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nr = fr + dr[dir];
                            int nc = fc + dc[dir];

                            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                                continue;
                            }

                            if (map[nr][nc] == 0) {
                                continue;
                            }

                            if (visited[nr][nc]) {
                                continue;
                            }

                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }

}