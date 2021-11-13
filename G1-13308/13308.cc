#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> price(N + 1);
    
    vector<vector<pair<int, int> > > adj(N + 1);

    for (int i = 1 ; i <= N; ++i) {
        cin >> price[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    priority_queue<tuple<long long, int, int> > pq;

    vector<vector<long long> > cost(N + 1, vector<long long> (2501, 1e18));

    cost[1][2500] = 0;
    pq.push({-cost[1][2500], -2500, 1});

    while (!pq.empty()) {
        auto [c, p, n] = pq.top();
        pq.pop();
        c = -c;
        p = -p;
        if (n == N) {
            cout << c << '\n';
            return 0;
        }
        if (c > cost[n][p]) continue;


        int np = min(p, price[n]);

        for (auto [nn, d]: adj[n]) {
            if (cost[nn][np] > cost[n][p] + 1LL * d * np) {
                cost[nn][np] = cost[n][p] + 1LL * d * np;
                pq.push({-cost[nn][np], -np, nn});
            }
        }
    }
}