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

    vector<int> p(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
    }

    vector<int> dp(N + 1, -1);
    dp[0] = 0;

    function<int(int)> f = [&](int n) {
        int& ret = dp[n];
        if (ret != -1) {
            return ret;
        }

        for (int i = 1; i <= n; ++i) {
            ret = max(ret, p[i] + f(n - i));
        }
        return ret;
    };

    cout << f(N) << '\n';
}
