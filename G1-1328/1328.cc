#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<vector<long long> > > dp(N + 1, vector<vector<long long> > (L + 1, vector<long long> (R + 1, 0)));

    dp[1][1][1] = 1;

    for (int n = 2; n <= N; ++n) {
        for (int l = 1; l <= L; ++l) {
            for (int r = 1; r <= R; ++r) {
                dp[n][l][r] = dp[n - 1][l - 1][r] + dp[n - 1][l][r - 1] + dp[n - 1][l][r] * (n - 2);
                dp[n][l][r] %= MOD;
            }
        }
    }

    cout << dp[N][L][R] << '\n';
}