#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    vector<int> arr(K);

    int maxLen = 0;
    for (auto &e: arr) {
        cin >> e;
        maxLen = max(maxLen, e);
    }

    long long l = 1;
    long long r = 1LL + maxLen;
    while (l + 1 < r) {
        long long num = 0;
        long long mid = (l + r) / 2;
        for (auto e: arr) {
            num += e / mid;
        }
        
        if (num < (long long)N) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l << '\n';
}
