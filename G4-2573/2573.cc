#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 300

int N, M;
int map[N_MAX][N_MAX] = {0};

bool visited[N_MAX][N_MAX] = {0};

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

// 얼음 기준 bfs 주변 물 개수 willMelt 저장
void bfs(int r, int c) {
    queue<pair<int, int> > q;
    int frontR, frontC, nextR, nextC;
    int willMelt[N_MAX][N_MAX] = {0};

    visited[r][c] = true;
    q.push({r, c});

    while (!q.empty()) {
        frontR = q.front().first;
        frontC = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            nextR = frontR + dr[dir];
            nextC = frontC + dc[dir];

            if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M) {
                continue;
            }
            if (visited[nextR][nextC]) {
                continue;
            }
            if (map[nextR][nextC] == 0) {
                willMelt[frontR][frontC]++;
                continue;
            }

            visited[nextR][nextC] = true;
            q.push({nextR, nextC});
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (willMelt[i][j] > 0) {
                map[i][j] = map[i][j] < willMelt[i][j] ? 0 : map[i][j] - willMelt[i][j];
            }
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

    int year = 0;
    while (1) {
        year++;
        fill(&visited[0][0], &visited[N][M], 0);
        int partNum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j);
                    partNum++;
                }
            }
        }

        if (partNum == 0) {
            cout << 0 << "\n";
            return 0;
        } else if (partNum > 1) {
            cout << year - 1 << "\n";
            return 0;
        }
    }
}