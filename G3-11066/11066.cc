#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        vector<int> arr(K + 1, 0);
        vector<vector<int> > dp(K + 1, vector<int> (K + 1, INF));
        vector<vector<int> > A(K + 1, vector<int> (K + 1, INF));
        for (int i = 1; i <= K; ++i) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
            dp[i - 1][i] = 0;
        }

        for (int i = 0; i + 2 <= K; ++i) {
            dp[i][i + 2] = arr[i + 2] - arr[i];
            A[i][i + 2] = i + 1;
        }

        for (int c = 3; c <= K; ++c) {
            for (int s = 0; s + c <= K; ++s) {
                for (int k = A[s][s + c - 1]; k <= A[s + 1][s + c]; ++k) {
                    if (dp[s][s + c] > dp[s][k] + dp[k][s + c] + arr[s + c] - arr[s]) {
                        A[s][s + c] = k;
                        dp[s][s + c] = dp[s][k] + dp[k][s + c] + arr[s + c] - arr[s];
                    }
                }
            }
        }
        cout << dp[0][K] << '\n';
    }
}
