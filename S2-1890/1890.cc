#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<long long> > v(N, vector<long long> (N));
    vector<vector<long long> > dp(N, vector<long long> (N, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> v[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (v[i][j] == 0) continue;
            if (i + v[i][j] < N) {
                dp[i + v[i][j]][j] += dp[i][j];
            }
            if (j + v[i][j] < N) {
                dp[i][j + v[i][j]] += dp[i][j];
            }
        }
    }

    cout << dp[N - 1][N - 1] << '\n';
}