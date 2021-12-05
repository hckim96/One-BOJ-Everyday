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
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i * i < sz; ++i) {
            if (!isPrime[i]) continue;
            for (int j = i * i; j < sz; j += i) {
                isPrime[j] = false;
            }
        }
        return isPrime;
    };
    auto isPrime = eraSieve(10000 + 1);

    int TC; cin >> TC;
    while (TC--) {
        int N;
        cin >> N;

        int answer;
        for (int i = 2; i <= N / 2; ++i) {
            if (isPrime[i] && isPrime[N - i]) {
                answer = i;
            }
        }
        cout << answer << ' ' << N - answer << '\n';
    }
}