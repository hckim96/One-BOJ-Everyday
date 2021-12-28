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

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= N; ++i) {
        if (i + 2 <= N) dp[i + 2] += dp[i] * 3;

        int j = i + 4; 
        while (j <= N) {
            dp[j] += dp[i] * 2;
            j += 2;
        }
    }
    cout << dp[N] << '\n';
}