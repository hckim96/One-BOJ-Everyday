#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int answer = 0;

// 아 위 오 왼
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
bool** visited;
int** map;
void dfs(int numOfDone, int score, int r, int c) {
    if (numOfDone == 4) {
        answer = answer < score ? score : answer;
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        int R = r + dr[dir];
        int C = c + dc[dir];
        if (R < 0 || R >= N || C < 0 || C >= M || visited[R][C] == true) {
            continue;
        } else {
            visited[R][C] = true;
            dfs(numOfDone + 1, score + map[R][C], R, C);
            visited[R][C] = false;
        }
    }
}
// check ㅗ ㅏ ㅓ ㅜ  -> 십자가 에서 하나 뺀 모양
void checkException() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int score = map[i][j];
            if (i == 0) {
                if (j == 0 || j == M - 1) {
                    continue;
                } else {
                    score += map[i + 1][j] + map[i][j + 1] + map[i][j - 1];
                }
            } else if (i == N - 1) {
                if (j == 0 || j == M - 1) {
                    continue;
                } else {
                    score += map[i - 1][j] + map[i][j + 1] + map[i][j - 1];
                }
            } else {
                if (j == 0) {
                    score += map[i - 1][j] + map[i + 1][j] + map[i][j + 1];
                } else if (j == M - 1) {
                    score += map[i - 1][j] + map[i + 1][j] + map[i][j - 1];
                } else {
                    score += map[i - 1][j] + map[i + 1][j] + map[i][j + 1] + map[i][j - 1];
                    score -= min(map[i - 1][j], min(map[i + 1][j], min(map[i][j + 1],  map[i][j - 1])));
                }
            }
            answer = answer < score ? score : answer;
        }
    }
}

int main () {
    cin >> N >> M;
    map = new int*[N];
    visited = new bool*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new int[M];
        visited[i] = new bool[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(0, 0, i, j);
        }
    }
    checkException();

    cout << answer << "\n";

}