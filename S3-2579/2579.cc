#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto &e: arr) {
        cin >> e;
    }

    vector<int> dp(N, 0);

    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[1] + arr[2], arr[0] + arr[2]);

    for (int i = 3; i < N; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
    }
    cout << dp[N - 1] << '\n';
}
