#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;

    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int> > dp(2, vector<int> (N));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> dp[i][j];
            }
        }

        dp[0][1] += dp[1][0];
        dp[1][1] += dp[0][0];
        
        for (int j = 2; j < N; ++j) {
            dp[0][j] += max(dp[1][j - 2], dp[1][j - 1]);
            dp[1][j] += max(dp[0][j - 2], dp[0][j - 1]);
        }

        cout << max(dp[0][N - 1], dp[1][N - 1]) << '\n';
    }
}