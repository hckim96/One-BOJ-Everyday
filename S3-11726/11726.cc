#include <iostream>

using namespace std;

#define N_MAX 1000

int dp[N_MAX + 1] = {0};
int N;

int main() {
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 1; i <= N - 2; i++) {
        dp[i + 2] = (dp[i + 1] + dp[i]) % 10007;
    }

    cout << dp[N] << "\n";
}