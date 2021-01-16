#include <iostream>

using namespace std;

int dp[11] = {0};
int T, N;

int f(int n) {
    if (dp[n] != 0) {
        return dp[n];
    }

    return dp[n] = f(n - 1) + f(n - 2) + f(n - 3);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    while (T--) {
        cin >> N;

        cout << f(N) << "\n";
    }
}