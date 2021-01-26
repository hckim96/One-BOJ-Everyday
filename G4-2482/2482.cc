#include <iostream>

using namespace std;

#define DIV 1000000003
#define N_MAX 1000

int N, K;

int main() {
    cin >> N >> K;
    
    int dp[N_MAX + 1][N_MAX + 1] = {0};
    for (int n = 0; n <= N; n++) {
        dp[n][0] = 1;
        dp[n][1] = n;
    }

    for (int n = 3; n <= N; n++) {
        for (int k = 2; 2 * k <= n + 1; k++) {
            dp[n][k] = (dp[n - 1][k] + dp[n - 2][k - 1]) % DIV;
        }
    }

    int answer = dp[N][K] - (K == 1 ? 0 : dp[N - 4][K - 2]);
    if (answer < 0) {
        answer += DIV;
    }
    cout << answer % DIV << "\n";
}