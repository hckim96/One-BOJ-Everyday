#include <iostream>
#include <queue>

using namespace std;

int R, C;
char map[50][50];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int answer = 0;
void bfs() {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] == 'W') {
                continue;
            }
            int distance[50][50];
            for (int i = 0; i < 50; i++) {
                for (int j = 0; j < 50; j++) {
                    distance[i][j] = -1;
                }
            }
            queue<pair<int, int> > q;

            distance[i][j] = 0;
            q.push({i, j});

            int maxDistance = 0;

            while (!q.empty()) {
                int frontR = q.front().first;
                int frontC = q.front().second;
                q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nextR = frontR + dr[dir];
                    int nextC = frontC + dc[dir];

                    if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) {
                        continue;
                    }
                    if (map[nextR][nextC] == 'W') {
                        continue;
                    }
                    if (distance[nextR][nextC] >= 0) {
                        continue;
                    }

                    distance[nextR][nextC] = distance[frontR][frontC] + 1;
                    maxDistance = max(maxDistance, distance[nextR][nextC]);
                    q.push({nextR, nextC});
                }
            }
            answer = max(answer, maxDistance);

        }
    }

}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    bfs();
    cout << answer << "\n";
}