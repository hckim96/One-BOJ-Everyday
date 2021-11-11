#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int> > dp(N * 5 + 1, vector<int> (M + 1, -1e9));
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {  
        int cpu, memory, priority;
        cin >> cpu >> memory >> priority;
        for (int j = dp.size() - 1 - priority; j >= 0; --j) {
            for (int k = dp[0].size() - 1; k >= 0; --k) {
                if (dp[j][k] == -1e9) continue;
                int ncpu = min(k + cpu, M);
                dp[j + priority][ncpu] = max(dp[j + priority][ncpu], dp[j][k] + memory);
            }
        }
    }

    for (int p = 0; p < dp.size(); ++p) {
        if (dp[p][M] >= K) {
            cout << p << '\n';
            return 0;
        }
    }
    cout << "-1\n";
}