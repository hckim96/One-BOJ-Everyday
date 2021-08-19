#include <iostream>

using namespace std;

#define MOD 1'000'000'007

// get K ^ (MOD - 2) % MOD
long long getInverse(long long K) {
    int ret = 1;
    int exp = MOD - 2;
    int base = K;

    while (exp) {
        if (exp & 1) {
            ret = (1LL * ret * base) % MOD;
        }

        exp >>= 1;
        base = (1LL * base * base) % MOD;
    }

    return ret;
}

int main() {
    long long N, K;
    cin >> N >> K;

    K = N - K < K ? N - K : K;

    int cnt = K;
    long long numerator = 1;
    long long denominator = 1;

    for  (int i = 0; i < cnt; ++i) {
        numerator *= N--;
        denominator *= K--;
        numerator %= MOD;
        denominator %= MOD;
    }

    cout << numerator * getInverse(denominator) % MOD << '\n';
}
