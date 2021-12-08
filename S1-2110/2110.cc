#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, C;
    cin >> N >> C;

    vector<int> x(N);
    for (auto& e: x) cin >> e;
    sort(all(x));

    auto check = [&](int d) {
        int cnt = 1;
        int prevIdx = 0;
        while (cnt < C) {
            int idx = prevIdx + 1;

            while (idx != N && x[idx] - x[prevIdx] < d) {
                ++idx;
            }
            if (idx == N) break;
            ++cnt;
            prevIdx = idx;
        }

        return cnt >= C;
    };

    int lo = 0;
    int hi = x[N - 1] - x[0] + 1;
    
    while (lo + 1 < hi) {
        int mid = lo + hi >> 1;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}