#include <iostream>
#include <queue>

using namespace std;

int horse_dr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int horse_dc[8] = {1, -1, 2, -2, 2, -2, 1, -1};
int monkey_dr[4] = {0, 0, 1, -1};
int monkey_dc[4] = {1, -1, 0, 0};

int K, W, H;
int map[200][200];

// r, c, numUsed
int visited[200][200][31] = {0};

int answer = 987654321;

void bfs() {
    queue<pair<pair<int, int>, int> > q;

    visited[0][0][0] = 0;
    q.push({{0, 0}, 0});

    while (!q.empty()) {
        int frontR = q.front().first.first;
        int frontC = q.front().first.second;
        int numUsed = q.front().second;
        q.pop();

        int nextR, nextC;

        // monkey
        for (int dir = 0; dir < 4; dir++) {
            nextR = frontR + monkey_dr[dir];
            nextC = frontC + monkey_dc[dir];
            if (nextR < 0 || nextR >= H || nextC < 0 || nextC >= W) {
                continue;
            }
            if (map[nextR][nextC] == 1 || visited[nextR][nextC][numUsed] >= 0) {
                continue;
            }

            visited[nextR][nextC][numUsed] = visited[frontR][frontC][numUsed] + 1;
            q.push({{nextR, nextC}, numUsed});
        }

        if (numUsed < K) {
            // horse
            for (int dir = 0; dir < 8; dir++) {
                nextR = frontR + horse_dr[dir];
                nextC = frontC + horse_dc[dir];

                if (nextR < 0 || nextR >= H || nextC < 0 || nextC >= W) {
                    continue;
                }
                if (map[nextR][nextC] == 1 || visited[nextR][nextC][numUsed + 1] >= 0) {
                    continue;
                }

                visited[nextR][nextC][numUsed + 1] = visited[frontR][frontC][numUsed] + 1;
                q.push({{nextR, nextC}, numUsed + 1});
            }
        }
    }
}


int main() {
    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
            for (int k = 0; k < 31; k++) {
                visited[i][j][k] = -1;
            }
        }
    }

    bfs();

    for (int i = 0; i <= K; i++) {
        if (visited[H -1][W - 1][i] != -1) {
            answer = min(answer, visited[H -1][W - 1][i]);
        }
    }

    if (answer == 987654321) {
        cout << -1 << "\n";
    } else {
        cout << answer << "\n";
    }

}