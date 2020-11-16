#include <iostream>

using namespace std;

long long GCD, LCM;
long long sumOfab = __LONG_LONG_MAX__;
long long a, b;

long long getGCD(long long big, long long small) {

    if (small == 0) {
        return big;
    } else {
        return getGCD(small, big % small);
    }
}

int main() {
    cin >> GCD >> LCM;

    long long alphaBeta = LCM / GCD;

    for (long long alpha = 1; alpha * alpha <= alphaBeta; alpha++) {
        long long beta = alphaBeta / alpha;
        long long remainder = alphaBeta % alpha;
        if (remainder == 0 && getGCD(alpha, beta) == 1) {
            if (alpha * GCD + beta * GCD < sumOfab) {
                a = alpha * GCD;
                b = beta * GCD;
            }
        }
    }

    cout << a << " " << b << "\n";

    return 0;
}