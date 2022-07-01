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
    map<int, int> m;
    pair<int, int> many = {0, 0};
    long long sum = 0;
    for (auto& e: v) {
        cin >> e;
        sum += e;
        ++m[e];
        if (m[e] > many.second) {
            many = {e, m[e]};
        } else if (m[e] == many.second) {
            if (e < many.first) {
                many = {e, m[e]};
            }
        }
    }
    // pair<int, int> ans = {-1, -1};
    int ans = 1e9;
    for (auto [n, cnt]: m) {
        if (cnt == many.second && n != many.first) {
            if (ans > n) {
                ans = n;
            }
        }
    }

    sort(all(v));
    cout << int(round((long double) sum / N)) << '\n';
    cout << v[N / 2] << '\n';
    cout << (ans != 1e9 ? ans : many.first) << '\n';
    cout << v.back() - v.front() << '\n';
}