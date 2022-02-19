#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

struct Edge {
    int to, c, f;
    Edge* reverse;
    Edge() {
        to = c = f = 0;
        reverse = nullptr; 
    }
    Edge(int to_, int c_) {
        f = 0;
        c = c_;
        to = to_;
        reverse = nullptr;
    }

    int residual() {
        return c - f;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, P;
    cin >> N >> P;

    vector<vector<Edge*> > adj(2 * N + 1);

    auto makeEdge = [&](int u, int v, int c) {
        auto e1 = new Edge(v, c);
        auto e2 = new Edge(u, 0);
        e1 -> reverse = e2;
        e2 -> reverse = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    };

    for (int i = 0; i < P; ++i) {
        int u, v;
        cin >> u >> v;
        makeEdge(2 * u, 2 * v - 1, 1);
        makeEdge(2 * v, 2 * u - 1, 1);
    }
    for (int i = 1; i <= N; ++i) {
        int c = 1;
        if (i == 1 || i == 2) c = 400;
        makeEdge(2 * i - 1, 2 * i, c);
    }

    int S = 1 * 2 - 1;
    int T = 2 * 2;
    int answer = 0;

    while (true) {
        vector<Edge*> prev(2 * N + 1, nullptr);
        queue<int> q;
        q.push(S);
        while (q.size()) {
            auto f = q.front();
            q.pop();
            for (auto e: adj[f]) {
                if (prev[e -> to]) continue;
                if (e -> residual() <= 0) continue;
                q.push(e -> to);
                prev[e -> to] = e;
                if (e -> to == T) break;
            }
            if (prev[T]) break;
        }

        if (!prev[T]) break;

        int flow = 1e9;
        for (int cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            flow = min(flow, prev[cur] -> residual());
        }

        for (int cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            prev[cur] -> f += flow;
            prev[cur] -> reverse -> f -= flow;
        }
        answer += flow;
    }
    cout << answer << '\n';
}