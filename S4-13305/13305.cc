#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> price(N), dist(N - 1);

    for (auto& e: dist) cin >> e;
    for (auto& e: price) cin >> e;

    long long answer = 0;

    long long cur = 1e18;
    long long dist_ = 0;
    for (int i = 0; i < N; ++i) {
        if (i) dist_ += dist[i - 1];
        if (cur > price[i]) {
            answer += cur * dist_;
            cur = price[i];
            dist_ = 0;
        }
    }
    answer += cur * dist_;
    
    cout << answer << '\n';
}