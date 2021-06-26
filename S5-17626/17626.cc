#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> dp(N + 1, 5);

    for (int i = 1; i * i <= N; ++i) {
        dp[i * i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j * j < i; ++j) {
            dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
        }
    }

    cout << dp[N] << '\n';
}
