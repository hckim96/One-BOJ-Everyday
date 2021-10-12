#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    const int MAXR = 500;

    vector<vector<long long> > dp(MAXR, vector<long long> (50001,0));
    vector<vector<long long> > dpSum(MAXR, vector<long long> (50001,0));

    dp[1][0] = dp[1][1] = 1;
    dpSum[1][0] = 1;
    dpSum[1][1] = 2;

    for (int i = 2; i < dp.size(); ++i) {
        dp[i][0] = 1;
        dpSum[i][0] = 1;
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[i][j] += dp[i - 1][j];
            if (j - i >= 0) dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= MOD;
            dpSum[i][j] = dpSum[i][j - 1] + dp[i][j];
            dpSum[i][j] %= MOD;
        }
    }

    while (TC--) {
        int a, b;
        cin >> a >> b;
        long long answer = 0;

        for (int i = 1; i < dp.size(); ++i) {
            int total = i * (i + 1) / 2;
            if (total > a + b) break;
            answer += dpSum[i][min(a, total)];
            if (total - b > 0) answer -= dpSum[i][i * (i + 1) / 2 - b - 1];
            answer = (answer + MOD) % MOD;
        }
        cout << answer << '\n';
    }
}