#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> memory(N, 0);
    vector<int> cost(N, 0);

    for (auto & e: memory) {
        cin >> e;
    }
    int totalCost = 0;
    for (auto & e: cost) {
        cin >> e;
        totalCost += e;
    }

    vector<int> dp(totalCost + 1, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = totalCost; j - cost[i] >= 0; --j) {
            dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
        }
    }

    for (int i = 0; i <= totalCost; ++i) {
        if (dp[i] >= M) {
            cout << i << '\n';
            return 0;
        }
    }
}