#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    
    int N, K;
    cin >> N >> K;

    vector<int> dp(K + 1, 1e9);
    dp[0] = 0;
    vector<int> a(N);
    for (auto& e: a) {
        cin >> e;
    }
    for (auto e: a) {
        for (int i = 0; i + e < dp.size(); ++i) {
            dp[i + e] = min(dp[i + e], dp[i] + 1);
        }
    }

    if (dp[K] == (int)1e9) {
        cout << "-1\n";
    } else {
        cout << dp[K] << '\n';
    }
}