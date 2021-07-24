#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long min, max;

    cin >> min >> max;

    int sqrtMax = sqrt(max);
    vector<bool> isPrime(sqrtMax + 1, true);

    for (int i = 2; i * i <= sqrtMax; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        for (int j = i * i; j <= sqrtMax; j += i) {
            isPrime[j] = false;
        }
    }

    vector<bool> isSqNum(max - min + 1, false);

    int sqrNumCnt = 0;

    for (int i = 2; i <= sqrtMax; ++i) {
        if (!isPrime[i]) {
            continue;
        }    

        long long k = ceil((double)min / ((long long)i * i));

        for (long long j = k * i * i; j <= max; j += i * i) {
            if (!isSqNum[j - min]) {
                isSqNum[j - min] = true;
                ++sqrNumCnt;
            }
        }
    }
    cout << max - min + 1 - sqrNumCnt << '\n';
}