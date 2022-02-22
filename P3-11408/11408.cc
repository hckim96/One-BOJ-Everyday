#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

struct Edge {
    int to, c, f, cost;
    Edge* reverse;

    Edge() {
        to = c = f = cost = 0;
        reverse = nullptr;
    }
    Edge(int to_, int c_, int cost_) {
        to = to_;
        c = c_;
        cost = cost_;
        f = 0;

        reverse = nullptr;
    }

    int reisidual() {
        return c - f;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1, 0), B(M + 1, 0);
    vector<vector<Edge*> > adj(N + M + 2);
    int S = 0;
    int T = adj.size() - 1;
    auto makeEdge = [&](int u, int v, int c, int cost) {
        auto e1 = new Edge(v, c, cost);
        auto e2 = new Edge(u, 0, -cost);
        e1 -> reverse = e2;
        e2 -> reverse = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    };
    
    for (int i = 1; i <= N; ++i) {
        makeEdge(S, i, 1, 0);
        int cnt = 0;
        cin >> cnt;
        while (cnt--) {
            int v, cost;
            cin >> v >> cost;
            makeEdge(i, N + v, 1, cost);
        }
    }
    for (int i = 1; i <= M; ++i) {
        makeEdge(N + i, T, 1, 0);
    }
    
    int maxFlow = 0;
    int minCost2 = 0;
    while (true) {
        vector<Edge*> prev(N + M + 2, nullptr);
        queue<int> q;
        vector<int> inQ(N + M + 2, false);
        vector<int> minCost(N + M + 2, 1e9);
        q.push(S);
        minCost[S] = 0;
        inQ[S] = true;
        while (q.size()) {
            int cur = q.front();
            q.pop();
            inQ[cur] = false;
            for (auto e: adj[cur]) {
                if (e -> reisidual() > 0 && minCost[e -> to] > minCost[cur] + e -> cost) {
                    minCost[e -> to] = minCost[cur] + e -> cost;
                    prev[e -> to] = e;
                    if (!inQ[e -> to]) {
                        q.push(e -> to);
                        inQ[e -> to] = true;
                    }
                }
            }
        }

        if (!prev[T]) break;
        
        int flow = 1e9;
        for (auto cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            flow = min(flow, prev[cur] -> reisidual());
        }

        for (auto cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            prev[cur] -> f += flow;
            prev[cur] -> reverse -> f -= flow;
        }
        maxFlow += flow;
        minCost2 += minCost[T];
    }

    cout << maxFlow << '\n';
    cout << minCost2 << '\n';
}