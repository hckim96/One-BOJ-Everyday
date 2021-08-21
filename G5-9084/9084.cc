#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> coin(N);

        for (auto& e: coin) {
            cin >> e;
        }

        int M;
        cin >> M;

        vector<int> dp(M + 1, 0);
        dp[0] = 1;
        
        for (auto e: coin) {
            for (int i = e; i <= M; ++i) {
                dp[i] += dp[i - e];
            }
        }

        cout << dp[M] << '\n';
    }
}