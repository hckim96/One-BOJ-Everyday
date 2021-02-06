#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> dp(1001);
    vector<int> dp2(1001);

    for (auto & e: arr) {
        cin >> e;
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j > i; --j) {
            if (arr[j] < arr[i]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        answer = max(answer, dp[i] + dp2[i] + 1);
    }
    cout << answer << "\n";
}
