#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define N_MAX 100

int N, M;
int map[N_MAX][N_MAX];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

vector<pair<int, int> > target;

void removeTarget() {
    for (auto it = target.begin(); it != target.end(); it++) {
        auto [r, c] = *it;
        map[r][c] = 0;
    }
}

void airBFS() {
    int visited[N_MAX][N_MAX] = {0};
    queue<pair<int, int> > q;

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }

            if (map[nr][nc] == 1) {
                visited[nr][nc]++;
                if (visited[nr][nc] >= 2) {
                    target.push_back({nr, nc});
                }
                continue;
            }

            if (visited[nr][nc] > 0) {
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int time = 0;

    while (true) {
        airBFS();
        
        if (target.size() == 0) {
            cout << time << "\n";
            return 0;
        } else {
            time++;
            removeTarget();
            target.clear();
        }
    }
}