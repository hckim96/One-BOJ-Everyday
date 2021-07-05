#include <iostream>
#include <vector>

using namespace std;

#define MOD 10007

int main() {
    int N;
    cin >> N;

    vector<vector<int> > comb(53, vector<int> (53, 1));

    for (int i = 1; i <= 52; ++i) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            comb[i][j] %= MOD;
        }
    }

    int ret = 0;
    for (int i = 1; i * 4 <= N; ++i) {
        ret += (i % 2 ? 1 : -1) * comb[13][i] * comb[52 - 4 * i][N - 4 * i];
        ret %= MOD;
    }

    if (ret < 0) {
        ret += MOD;
    }

    cout << ret << '\n';
}
