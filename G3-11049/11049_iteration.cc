#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int> > matrix(N, {0, 0});

    for (auto & e: matrix) {
        cin >> e.first >> e.second;
    }

    vector<vector<int> > dp(N, vector<int> (N, INT32_MAX));
    
    for (int i = 0; i < N; ++i) {
        dp[i][i] = 0;
    }
    
    for (int l = 1; l <= N - 1; ++l) {
        for (int i = 0; i + l < N; ++i) {
            for (int k = i; k < i + l; ++k) {
                dp[i][i + l] = min(dp[i][i + l], dp[i][k] + dp[k + 1][i + l] + matrix[i].first * matrix[k].second * matrix[i + l].second);
            }
        }
    }

    cout << dp[0][N - 1] << "\n";
}
