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

    vector<int> T(N), P(N);

    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> P[i];
    }
    
    int answer = 0;
    vector<int> dp(N + 1, 0);
    function<int(int)> f = [&](int cur) {
        if (cur == N) {
            return 0;
        }

        if (cur > N) {
            return (int)-1e9;
        }

        if (dp[cur]) {
            return dp[cur];
        }

        return dp[cur] = max(f(cur + 1), f(cur + T[cur]) + P[cur]);
    };

    f(0);
    cout << dp[0] << '\n';
}