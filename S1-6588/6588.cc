#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> isPrime(1e6 + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < isPrime.size(); ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j < isPrime.size(); j +=i) {
            isPrime[j] = false;
        }
    }
    vector<int> prime;
    for (int i = 3; i < isPrime.size(); i += 2) {
        if (isPrime[i]) prime.push_back(i);
    }

    int N;
    while (cin >> N && N) {
        for (auto e: prime) {
            if (isPrime[N - e]) {
                cout << N << " = " << e << " + " << N - e << '\n';
                break;
            }
        }
    }
}