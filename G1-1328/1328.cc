#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<int> isPrime(N + 1, true);
    isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    int sum = 0;
    int min = N + 1;

    for (int i = M; i <= N; ++i) {
        if (min == N + 1 && isPrime[i]) {
            min = i;
        }

        if (isPrime[i]) {
            sum += i;
        }
    }

    if (sum) {
        cout << sum << '\n';
        cout << min << '\n';
    } else {
        cout << "-1\n";
    }
}