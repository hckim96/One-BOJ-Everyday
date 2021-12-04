#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    auto eraSieve = [&](int sz) {
        vector<int> isPrime(sz, true);
        isPrime[1] = false;
        for (int i = 2; i * i < sz; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < sz; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    };
    auto isPrime = eraSieve(123456 * 2 + 1);

    int N;
    while (cin >> N && N) {
        int cnt = 0;

        for (int i = N + 1; i <= 2 * N; ++i) {
            if (isPrime[i]) ++cnt;
        }
        cout << cnt << '\n';
    }

}