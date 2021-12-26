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

    vector<int> dp(N + 1, -1);
    dp[0] = 0;
    for (int i = 1; i * i <= N; ++i) {
        dp[i * i] = 1;
    }
    function<int(int)> f = [&](int n) {
        int& ret = dp[n];

        if (ret != -1) return ret;
        if (n == 1) return ret = 1;

        ret = 1e9;
        for (int i = 1; i * i <= n; ++i) {
            ret = min(ret, f(n - i * i) + 1);
        }
        return ret;
    };
    cout << f(N) << '\n';
}