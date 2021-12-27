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
    vector<long long> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    vector<long long> dp(N, 0);
    for (int i = 0; i < N; ++i) {
        dp[i] = a[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (a[j] < a[i] && dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
            }
        }
    }

    cout << *max_element(all(dp)) << '\n';
}