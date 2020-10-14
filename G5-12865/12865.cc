#include <iostream>

using namespace std;

int N, K;
int weight[100];
int value[100];

int dp[100][100001];

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
                if (j < weight[i]) {
                    if (i == 0) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    if (i == 0) {
                        dp[i][j] = value[i];
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
                    }
                }
        }
    }

    cout << dp[N - 1][K] << "\n";
}