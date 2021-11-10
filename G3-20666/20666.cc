#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<long long> C(N + 1, 0);
    for (int i = 1; i <= N; ++i) cin >> C[i];
    int P;
    cin >> P;

    vector<vector<pair<long long, long long> > > v(N + 1);
    while (P--) {
        int a, b, t;
        cin >> a >> b >> t;
        v[a].push_back({b, t});
        C[b] += t;
    }

    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
   
    for (int i = 1; i <= N; ++i) {
        pq.push({C[i], i});
    }
    
    vector<int> selected(N + 1, false);
    int selectedCnt = 0;
    while (selectedCnt < M) {
        auto [c, idx] = pq.top();
        pq.pop();
        if (c > C[idx]) continue;
        if (selected[idx]) continue;
        selected[idx] = true;
        ++selectedCnt;
        for (auto [b, t]: v[idx]) {
            if (selected[b]) continue;
            C[b] -= t;
            pq.push({C[b], b});
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        if (selected[i]) ans = max(ans, C[i]);
    }
    cout << ans << '\n';
}