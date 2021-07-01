#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 1000000007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N, 0);

    for (auto &e: A) {
        cin >> e;
    }

    sort(A.begin(), A.end());

    vector<int> pow2(N);

    pow2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    int answer = 0;

    for (int i = 0; N - i - 1 > i; ++i) {
        answer = (0LL + answer + 1LL * (pow2[N - i - 1] - pow2[i] + MOD) * ((A[N - i - 1] - A[i]) % MOD)) % MOD;
    }

    cout << answer << '\n';
}
