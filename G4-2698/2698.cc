#include <iostream>

using namespace std;

#define N_MAX 100
#define K_MAX 100

int dp[2][N_MAX + 1][K_MAX + 1] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    dp[1][1][0] = 1;
    dp[0][1][0] = 1;
    dp[1][2][0] = 1;
    dp[1][2][1] = 1;
    dp[0][2][0] = 2;
    dp[0][2][1] = 0;

    for (int n = 3; n <= N_MAX; n++) {
        for (int k = 0; k <= n - 1; k++) {
            dp[0][n][k] = dp[1][n - 1][k] + dp[0][n - 1][k];
            dp[1][n][k] = (k == 0 ? 0 : dp[1][n - 1][k - 1]) + dp[0][n - 1][k];
        }
    }

    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << dp[0][n][k] + dp[1][n][k] << "\n";
    }
}