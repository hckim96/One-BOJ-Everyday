#include <iostream>

using namespace std;

#define N_MAX 500

int M, N;

int map[N_MAX][N_MAX] = {0};
int visited[N_MAX][N_MAX] = {0};
int dp[N_MAX][N_MAX] = {0};

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

// getRouteNum to (N - 1, M - 1)  from (r, c)
int getRouteNum(int r, int c) {
    if (r == M - 1 && c == N - 1) {
        return 1;
    }
    if (dp[r][c] >= 0) {
        return dp[r][c];
    }

    int nextR, nextC;
    int ret = 0;

    for (int dir = 0; dir < 4; dir++) {
        nextR = r + dr[dir];
        nextC = c + dc[dir];

        if (nextR < 0 || nextR >= M || nextC < 0 || nextC >= N) {
            continue;
        }
        if (visited[nextR][nextC] == 1) {
            continue;
        }

        if (map[nextR][nextC] >= map[r][c]) {
            continue;
        }

        visited[nextR][nextC] = 1;
        ret += getRouteNum(nextR, nextC);
        visited[nextR][nextC] = 0;
    }

    return dp[r][c] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    fill(&dp[0][0], &dp[0][0] + (N_MAX) * (N_MAX), -1);
    visited[0][0] = 1;

    cout << getRouteNum(0, 0) << "\n";
}