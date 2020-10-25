#include <iostream>

using namespace std;

int map[16][16] = {0};
int N;

int answer = 0;

// 0 1 2 동 남동 남
enum shape {
    EAST,
    SOUTH_EAST,
    SOUTH
};

// 동 남동 남
int dr[3] = {0, 1, 1};
int dc[3] = {1, 1, 0};

void dfs(int r, int c, int shape) {
    if (r == N - 1 && c == N - 1) {
        answer++;
        return;
    }

    for (int dir = 0; dir < 3; dir++) {
        // check if can move to direction 
        if (shape == EAST && dir == 2) {
            continue;
        }
        if (shape == SOUTH && dir == 0) {
            continue;
        }

        int nextR = r + dr[dir];
        int nextC = c + dc[dir];

        if (nextR >= N || nextC >= N) {
            // out of map
            continue;
        }
        
        // is wall
        if (map[nextR][nextC] == 1) {
            continue;
        }
        if (dir == 1 && (map[nextR - 1][nextC] == 1 || map[nextR][nextC - 1] == 1)) {
            continue;
        }

        dfs(nextR, nextC, dir);
    }
}
int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, 1, EAST);

    cout << answer << "\n";
}