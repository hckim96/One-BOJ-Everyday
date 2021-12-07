#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<char> > answer(N, vector<char> (N, '*'));
    function<void(int, int, int)> f = [&](int r, int c, int sz) {
        if (sz == 3) {
            answer[r + 1][c + 1] = ' ';
            return;
        }

        int third = sz / 3;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == 1 && j == 1) {
                    for (int k = 0; k < third; ++k) {
                        for (int l = 0; l < third; ++l) {
                            answer[r + i * third + k][c + j * third + l] = ' ';
                        }
                    }
                    continue;
                }
                f(r + i * third, c + j * third, sz / 3);
            }
        }
    };
    f(0, 0, N);
    for (auto e: answer) {
        for (auto ee: e) {
            cout << ee;
        }
        cout << '\n';
    }
}