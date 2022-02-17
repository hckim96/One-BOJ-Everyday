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

    vector<int> a(N);
    vector<vector<int> > dp(N, vector<int> (500001, -1));
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    
    dp[0][0] = 0;
    dp[0][a[0]] = a[0];
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= 500000; ++j) {
            if (dp[i - 1][j] == -1) continue;
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j + a[i] <= 500000) dp[i][j + a[i]] = max(dp[i][j + a[i]], dp[i - 1][j] + a[i]);
            if (a[i] < j) {
                dp[i][j - a[i]] = max(dp[i][j - a[i]], dp[i - 1][j]);
            } else {
                dp[i][a[i] - j] = max(dp[i][a[i] - j], dp[i - 1][j] + a[i] - j);
            }
        }
    }
    if (dp[N - 1][0] > 0) {
        cout << dp[N - 1][0] << '\n';
    } else {
        cout << "-1\n";
    }
}