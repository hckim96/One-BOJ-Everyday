#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<int> v(N);
    int totalSum = 0;
    for (auto& e: v) {
        cin >> e;
        totalSum += e;
    }

    auto check = [&](int x) {
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += v[i];
            if (sum >= x) {
                ++cnt;
                sum = 0;
                if (cnt >= K) {
                    return true;
                }
            }
        }
        return false;
    };

    int lo = 0;
    int hi = totalSum + 1;

    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    cout << lo << '\n';
}