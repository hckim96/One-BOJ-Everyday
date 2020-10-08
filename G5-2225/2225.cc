#include <iostream>

using namespace std;

#define DIVISOR 1000000000

int N, K;

// n , k
int dp[201][201]= {};

int main() {
    cin >> N >> K;

    int GREATER = N > K ? N : K;

    for (int i = 1; i <= GREATER; i++) {
        dp[0][i] = 1;
        dp[i][1] = 1;
    }

    for (int n = 1; n <= N; n++) {
        for (int k = 2; k <= K; k++) {
            dp[n][k] = (dp[n - 1][k] + dp[n][k - 1]) % DIVISOR;
        }
    }

    cout << dp[N][K] << "\n";
}