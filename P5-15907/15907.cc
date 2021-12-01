#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> time(N);
    for(auto& e: time) cin >> e;

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

    auto isPrime = eraSieve(2e6 + 1);
    int answer = 0;
    vector<int> cnt(2e6 + 1, 0);
    for (int k = 2; k < 2e6 + 1; ++k) {
        if (!isPrime[k]) continue;
        if (k > 4000000 / N) break;
        for (auto e: time) answer = max(answer, ++cnt[e % k]);
        for (auto e: time) --cnt[e % k];
    }
    cout << answer << '\n';   
}