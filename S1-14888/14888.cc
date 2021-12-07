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

    vector<int> A(N);
    for (auto& e: A) cin >> e;

    vector<int> cnt(4, 0);
    for (auto& e: cnt) cin >> e;

    vector<int> ops(N - 1);
    int ansMin = 1e9;
    int ansMax = -1e9;
    function<void(int)> f = [&](int added) {
        if (added == N - 1) {
            int result = A[0];
            for (int i = 0; i < ops.size(); ++i) {
                if (ops[i] == 0) {
                    result += A[i + 1];
                } else if (ops[i] == 1) {
                    result -= A[i + 1];
                } else if (ops[i] == 2) {
                    result *= A[i + 1];
                } else {
                    result /= A[i + 1];
                }
            }

            ansMin = min(ansMin, result);
            ansMax = max(ansMax, result);
            return;
        }

        for (int i = 0; i < 4; ++i) {
            if (cnt[i]) {
                --cnt[i];
                ops[added] = i;
                f(added + 1);
                ++cnt[i];
            }
        }
    };

    f(0);
    cout << ansMax << '\n';
    cout << ansMin << '\n';
}