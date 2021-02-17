#include <iostream>

using namespace std;

#define N_MAX 500

int N;
int arr[N_MAX][N_MAX] = {0};
int dp[N_MAX][N_MAX] = {0};

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int dfs(int r, int c) {
    if (dp[r][c]) {
        return dp[r][c];
    }

    dp[r][c] = 1;

    int tmp = 0;
    for (int dir = 0; dir < 4; ++dir) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            continue;
        }

        if (arr[nr][nc] <= arr[r][c]) {
            continue;
        }

        tmp = max(tmp, dfs(nr, nc));
    }

    dp[r][c] += tmp;
    return dp[r][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer << '\n';
}
