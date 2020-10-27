#include <iostream>
#include <queue>

using namespace std;

int R, C;
int map[100][100] = {0};

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void bfs() {

    queue<pair<int, int> > q;
    bool visited[100][100] = {0};
    q.push({0, 0});

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

            if (visited[nextR][nextC]) {
                continue;
            }

            if (map[nextR][nextC] == 0) {
                q.push({nextR, nextC});
                visited[nextR][nextC] = true;

            } else {
                map[nextR][nextC] = 2;
                visited[nextR][nextC] = true;
                
            }
        }

    }
}

int makeAir() {
    int cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0;j < C; j++) {
            if (map[i][j] == 2) {
                cnt++;
                map[i][j] = 0;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }

    int time = 0;
    int prev, now;
    while (true) {
        bfs();
        now = makeAir();
        time++;
        if (now == 0) {
            time--;
            cout << time << "\n";
            cout << prev << "\n";
            return 0;
        } else {
            prev = now;
        }
    }
}

