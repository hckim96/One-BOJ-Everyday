#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<bool> isPrime(N + 1, true);

    isPrime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (!isPrime[i]) {
            continue;
        }

        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }


    for (int i = M; i <= N; ++i) {
        if (isPrime[i]) {
            cout << i << '\n';
        }
    }
}