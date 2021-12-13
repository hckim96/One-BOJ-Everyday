#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    long long N, C;
    cin >> N >> C;

    vector<long long> v(N);
    for (auto& e: v) cin >> e;

    map<long long, int> m, m1;

    function<void(int, long long)> f = [&](int cur, long long sum) {
        if (cur == N / 2) {
            ++m[sum];
            return;
        }

        f(cur + 1, sum);
        f(cur + 1, sum + v[cur]);
    };

    f(0, 0);
    if (m[0] == 0) m[0] = 1;

    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin()) it -> second += prev(it) -> second;
    }

    function<void(int, long long)> f2 = [&](int cur, long long sum) {
        if (cur == N) {
            ++m1[sum];
            return;
        }

        f2(cur + 1, sum);
        f2(cur + 1, sum + v[cur]);
    };
    f2(N / 2, 0);

    long long answer = 0;
    for (auto it = m1.begin(); it != m1.end(); ++it) {
        if (it -> first <= C) {
            auto it2 = m.lower_bound(C - it -> first);
            if (it2 == m.end()) --it2;
            if (it2 -> first + it -> first > C) {
                if (it2 == m.begin()) continue;
                --it2;
            }
            answer += it -> second * it2 -> second;
        }
    }
    cout << answer << '\n';
}