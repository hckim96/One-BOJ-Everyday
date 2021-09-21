#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<long long> > dp(N + 1, vector<long long> (2, 0));

    dp[1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[N][0] + dp[N][1] << '\n';
}