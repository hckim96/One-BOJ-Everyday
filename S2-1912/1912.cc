#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> arr(N);

    for (auto& e: arr) {
        cin >> e;
    }

    vector<int> dp(N, -INF);

    int answer;
    answer = dp[0] = arr[0];
    
    for (int i = 1; i < N; ++i) {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer << '\n';
}