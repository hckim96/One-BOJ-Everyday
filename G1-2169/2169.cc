#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr(N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int> > dp(N, vector<int> (M, -INF));

    dp[0][0] = arr[0][0];
    for (int j = 1; j < M; ++j) {
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    }

    for (int i = 1; i < N; ++i) {
        vector<int> right(M, 0);
        vector<int> left(M, 0);

        for (int j = 0; j < M; ++j) {
            dp[i][j] = dp[i - 1][j] + arr[i][j];
        }

        right[0] = dp[i][0];
        left[M - 1] = dp[i][M - 1];

        for (int j = 1; j < M; ++j) {
            right[j] = max(right[j - 1] + arr[i][j], dp[i][j]);
            left[M - 1 - j] = max(left[M - 1 - j + 1] + arr[i][M - 1 - j], dp[i][M - 1 - j]);
        }

        for (int j = 0; j < M; ++j) {
            dp[i][j] = max(dp[i][j], max(right[j], left[j]));
        }
    }

    cout << dp[N - 1][M - 1] << '\n';
}