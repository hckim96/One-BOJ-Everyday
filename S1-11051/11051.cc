#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;
    int MOD = 10007;

    vector<vector<int> > comb(N + 1, vector<int> (K + 1, 1));

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j < min(i, K + 1); ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= MOD;
        }
    }

    cout << comb[N][K] << '\n';
    
}