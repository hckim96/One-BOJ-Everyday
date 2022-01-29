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

    vector<int> dp(N + 1, 0);

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (i - 1 > 0) dp[i] |= !dp[i - 1];
        if (i - 3 > 0) dp[i] |= !dp[i - 3];
    }

    if (dp[N] == 1) {
        cout << "SK\n";
    } else {
        cout << "CY\n";
    }
}