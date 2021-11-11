#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> arr(N, 0);
    for (auto& e: arr) cin >> e;
    vector<int> dp(N, 0);

    int max_, min_;
    for (int i = 0; i < N; ++i) {
        max_ = arr[i];
        min_ = arr[i];
        for (int j = i - 1; j >= 0; --j) {
            max_ = max(max_, arr[j + 1]);
            min_ = min(min_, arr[j + 1]);
            dp[i] = max(dp[i], dp[j] + max_ - min_);
        }
        max_ = max(max_, arr[0]);
        min_ = min(min_, arr[0]);
        dp[i] = max(dp[i], max_ - min_);
    }
    cout << dp[N - 1] << '\n';
}