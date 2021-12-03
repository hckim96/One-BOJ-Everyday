#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<long long> W(N), E(N);
    for (auto& e: W) cin >> e;
    for (auto& e: E) cin >> e;

    vector<vector<long long> > w_max(N, vector<long long> (N, 0)), e_max(N, vector<long long> (N, 0));

    for (int k = 1; k <= N; ++k) {
        for (int i = 0; i + k - 1 < N; ++i) {
            if (k == 1) {
                w_max[i][i] = W[i];
                e_max[i][i] = E[i];
            } else {
                w_max[i][i + k - 1] = max(w_max[i][i + k - 2], W[i + k - 1]);
                e_max[i][i + k - 1] = max(e_max[i][i + k - 2], E[i + k - 1]);
            }
        }
    }

    vector<long long> dp(N, 1e18);

    for (int i = 0; i < N; ++i) {
        dp[i] = w_max[0][i] * e_max[0][i];
        for (int j = 0; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + w_max[j + 1][i] * e_max[j + 1][i]);
        }
    }

    cout << dp[N - 1] << '\n';
}