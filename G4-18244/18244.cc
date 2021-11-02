#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> > (10, vector<long long> (5, 0)));

    for (int i = 0; i <= 9; ++i) {
        dp[1][i][2] = 1;
    }

    const long long MOD = 1e9 + 7;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            if (j + 1 <= 9) {
                dp[i][j][-2 + 2] += dp[i - 1][j + 1][-1 + 2];

                dp[i][j][-1 + 2] += dp[i - 1][j + 1][0 + 2];
                dp[i][j][-1 + 2] += dp[i - 1][j + 1][1 + 2];
                dp[i][j][-1 + 2] += dp[i - 1][j + 1][2 + 2];
            }

            if (j - 1 >= 0) {
                dp[i][j][1 + 2] += dp[i - 1][j - 1][0 + 2];
                dp[i][j][1 + 2] += dp[i - 1][j - 1][-1 + 2];
                dp[i][j][1 + 2] += dp[i - 1][j - 1][-2 + 2];
                
                dp[i][j][2 + 2] += dp[i - 1][j - 1][1 + 2];
            }            
            
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
            dp[i][j][3] %= MOD;
            dp[i][j][4] %= MOD;
        }
    }
    long long answer = 0;
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 4; ++j) {
            answer += dp[N][i][j];
            answer %= MOD;
        }
    }

    cout << answer << '\n';
}