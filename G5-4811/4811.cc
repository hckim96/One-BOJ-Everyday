#include <iostream>

using namespace std;

#define N_MAX 30

int N;

// 8byte 9e18  (4byte signed : 2e9)
long long dp[N_MAX + 1][N_MAX + 1];

int main() {
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        dp[0][0] = 1;
        for (int j = 1; j <= N; j++) {
            dp[0][j] = dp[0][j - 1];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= N - i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j + 1];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j + 1];
                }
            }
        }

        cout << dp[N][0] << "\n";
    }
    return 0;
}