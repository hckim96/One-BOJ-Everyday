#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    int maxLen = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        dp[num] = dp[num - 1] + 1;
        maxLen = maxLen > dp[num] ? maxLen : dp[num];
    }

    cout << N - maxLen << "\n";
}
