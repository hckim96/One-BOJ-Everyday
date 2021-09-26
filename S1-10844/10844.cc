#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int MOD = 1000000000;

    int N;
    cin >> N;

    vector<vector<int> > dp(N + 1, vector<int> (10, 0));

    for (int i = 1; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j < 9; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
        dp[i][9] = dp[i - 1][8];
    }

    long long answer = 0;
    for (int i = 0; i < 10; ++i) {
        answer += dp[N][i];
    }
    cout << answer % MOD << '\n';
} 