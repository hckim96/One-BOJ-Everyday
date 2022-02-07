#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;
    int S, D;
    cin >> S >> D;

    vector<vector<pair<long long, long long> > > adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<vector<long long> > dist(N + 1, vector<long long> (N, 1e18));
    priority_queue<tuple<long long, long long, long long> > pq;
    dist[S][0] = 0;
    // dist, n, len
    pq.push({-dist[S][0], S, 0});

    while (pq.size()) {
        auto [td, tn, tl] = pq.top();
        pq.pop();
        td = -td;
        if (dist[tn][tl] < td) continue;
        if (tl == N - 1) continue;

        for (auto [nn, nw]: adj[tn]) {
            if (dist[nn][tl + 1] > td + nw) {
                dist[nn][tl + 1] = td + nw;
                pq.push({-dist[nn][tl + 1], nn, tl + 1});
            }
        }
    }

    auto f = [&](int tax) {
        long long ret = 1e18;
        for (long long i = 1; i < N; ++i) {
            ret = min(ret, 1LL * dist[D][i] + i * tax);
        }
        return ret;
    };

    int tax = 0;
    cout << f(0) << '\n';
    for (int i = 0; i < K; ++i) {
        int p;
        cin >> p;
        tax += p;
        cout << f(tax) << '\n';
    }
}