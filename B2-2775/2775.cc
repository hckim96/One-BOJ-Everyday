#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    vector<vector<int> > dp(15, vector<int> (15, 0));

    for (int i = 0; i < 15; ++i) {
        for (int j = 1; j < 15; ++j) {
            if (i) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = j;
            }
        }
    }

    while (T--) {
        int k, n;
        cin >> k >> n;
        cout << dp[k][n] << '\n';
    }
}
