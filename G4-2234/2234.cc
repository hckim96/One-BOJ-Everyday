#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 50

int N, M;
int arr[N_MAX][N_MAX] = {0};
int visited[N_MAX][N_MAX] = {0};
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

vector<int> areaOfRoom(1, 0);

void bfs(int r, int c, int roomNum) {

    queue<pair<int, int> > q;
    visited[r][c] = roomNum;
    q.push({r, c});
    areaOfRoom[roomNum]++;

    while (!q.empty()) {
        auto [fr, fc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];
            
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }

            if (visited[nr][nc] > 0) {
                continue;
            }
            
            if (arr[fr][fc] & (1 << dir)) {
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = roomNum;
            areaOfRoom[roomNum]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int roomNum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                areaOfRoom.push_back(0);
                bfs(i, j, ++roomNum);
            }
        }
    }

    int maxArea = 0;
    for (auto it = areaOfRoom.begin() + 1; it != areaOfRoom.end(); it++) {
        maxArea = max(maxArea, *it);
    }

    cout << roomNum << "\n";
    cout << maxArea << "\n";

    int maxSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            int nr, nc;
            for (int dir = 0; dir < 4; dir++) {
                nr = i + dr[dir];
                nc = j + dc[dir];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                    continue;
                }

                if (visited[nr][nc] == visited[i][j]) {
                    continue;
                }
                
                if (arr[i][j] & (1 << dir)) {
                    maxSum = max(maxSum, areaOfRoom[visited[i][j]] + areaOfRoom[visited[nr][nc]]);
                }

            }
        }
    }
    cout << maxSum << "\n";
}