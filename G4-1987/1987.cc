#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define R_MAX 20

int R, C;
char map[R_MAX][R_MAX];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

int visited[26] = {0};
int answer = 0;
void dfs(int r, int c, int cnt) {
    int nextR, nextC;
    bool canMove = false;

    for (int dir = 0; dir < 4; dir++) {
        nextR = r + dr[dir];
        nextC = c + dc[dir];

        if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) {
            continue;
        }

        if (visited[map[nextR][nextC] - 'A'] == 1) {
            continue;
        }

        visited[map[nextR][nextC] - 'A'] = 1;
        dfs(nextR, nextC, cnt + 1);
        visited[map[nextR][nextC] - 'A'] = 0;
        canMove = true;
    }

    if (!canMove) {
        answer = max(answer, cnt);
    }
}

int main() {
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < C; j++) {
            map[i][j] = tmp[j];
        }
    }

    visited[map[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    cout << answer << "\n";
}