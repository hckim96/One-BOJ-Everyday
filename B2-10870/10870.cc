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

    vector<int> dp(N + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[N] << '\n';
}