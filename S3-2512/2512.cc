#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> v(N);
    for (auto& e: v) {
        cin >> e;
    }
    int M;
    cin >> M;

    int lo = 1;
    int hi = *max_element(all(v)) + 1;

    auto check = [&](int val) {
        int sum = 0;
        for (auto e: v) {
            sum += min(val, e);
        }
        return sum <= M;
    };

    while (lo + 1 < hi) {
        auto mid = lo + hi >> 1;
        if (check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
    
}