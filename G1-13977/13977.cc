#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int myPower(int a, int n) {
    int ret = 1;

    while (n) {
        if (n & 1) {
            ret = 1LL * ret * a % MOD;
        }
        a = 1LL * a * a % MOD;
        n >>= 1;
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;
    vector<int> factorial(4000001, 1);

    for (int i = 1; i < factorial.size(); ++i) {
        factorial[i] = 1LL * factorial[i - 1] * i % MOD;
    }

    while (M--) {
        int N, K;
        cin >> N >> K;

        int numerator = factorial[N];
        int denominator = 1LL * factorial[K] * factorial[N - K] % MOD;
        denominator = myPower(denominator, MOD - 2);

        cout << 1LL * numerator * denominator % MOD << '\n';
    }
}
