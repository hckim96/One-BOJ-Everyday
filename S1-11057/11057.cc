#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    int MOD = 10007;
    
    vector<vector<long long> > dp(N + 1, vector<long long> (10, 0));

    for (int j = 0; j <= 9; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 9; j >= 0; --j) {
            if (j != 9) dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
            else dp[i][j] = dp[i - 1][j];
            dp[i][j] %= MOD;
        }
    }

    cout << accumulate(all(dp[N]), 0LL) % MOD << '\n';
}