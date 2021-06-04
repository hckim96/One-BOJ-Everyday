#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int W, N;
    cin >> W >> N;
    
    vector<int> A(N, 0);

    for (auto & e: A) {
        cin >> e;
    }

    vector<bool> dp(400001, false);

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int sum = A[i] + A[j];
            if (W - sum > 400000 || W - sum < 0) {
                continue;
            }

            if (dp[W - sum]) {
                cout << "YES\n";
                return 0;
            }
        }

        for (int k = 0; k < i; ++k) {
            dp[A[k] + A[i]] = true;
        }
    }

    cout << "NO\n";
}
