#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    for (auto& e: v) cin >> e;

    vector<int> dp(K + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j + v[i] <= K; ++j) {
            dp[j + v[i]] += dp[j];
        }
    }

    cout << dp[K] << '\n';
}