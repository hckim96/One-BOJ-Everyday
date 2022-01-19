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

    vector<int> dp(N + 1);
    dp[0] = 1;
    dp[1] = 3;

    for (int i = 2; i <= N; ++i) {
        dp[i] = 2 * dp[i - 1] + dp[i - 2];
        dp[i] %= 9901;
    }
    cout << dp[N] << '\n';
}