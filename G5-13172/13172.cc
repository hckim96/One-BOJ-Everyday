#include <iostream>

using namespace std;

#define MOD 1'000'000'007

int sqr(int base, int exp) {
    int ret = 1;
    int mul = base;
    while (exp) {
        if (exp & 1) {
            ret = 1LL * ret * mul % MOD;
        }

        mul = 1LL * mul * mul % MOD;
        exp >>= 1;
    }

    return ret;
}

int getInverse(int num) {
    return sqr(num, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    int answer = 0;

    while (M--) {
        int N, S;
        cin >> N >> S;

        answer = (0LL + answer + 1LL * S * getInverse(N)) % MOD;
    }
    cout << answer << '\n';
}