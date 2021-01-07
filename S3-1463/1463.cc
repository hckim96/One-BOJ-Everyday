#include <iostream>

using namespace std;

#define N_MAX 1000000

int N;
int dp[N_MAX + 1] = {0};

int main() {
    cin >> N;

    dp[1] = 0;
    
    // bottom up
    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }
    cout << dp[N] << "\n";
}