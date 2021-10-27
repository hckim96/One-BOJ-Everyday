#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    string s;
    cin >> s;

    vector<vector<int> > cost(M, vector<int> (M));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cost[i][j];
        }
    }

    for (int j = 0; j < M; ++j) {
        for (int i = 0; i < M; ++i) {
            for (int k = 0; k < M; ++k) {
                if (cost[i][k] > cost[i][j] + cost[j][k]) {
                    cost[i][k] = cost[i][j] + cost[j][k];
                }
            }
        }
    }

    vector<vector<int> > cost2(N, vector<int> (M));
    vector<vector<int> > pCost2(N, vector<int> (M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cost2[i][j] = cost[s[i] - 'a'][j];
            pCost2[i][j] = cost2[i][j];
            if (i) pCost2[i][j] += pCost2[i - 1][j];
        }
    }

    vector<vector<int> > dp(N, vector<int> (M, 1e9));
    vector<int> dpMin(N, 1e9);

    for (int j = 0; j < M; ++j) {
        dp[K - 1][j] = pCost2[K - 1][j];
        dpMin[K - 1] = min(dpMin[K - 1], dp[K - 1][j]);
    }

    for (int i = K; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = min(dp[i - 1][j] + cost2[i][j], dpMin[i - K] + pCost2[i][j] - pCost2[i - K][j]);
            dpMin[i] = min(dpMin[i], dp[i][j]);
        }
    }

    cout << dpMin[N - 1] << '\n';
}