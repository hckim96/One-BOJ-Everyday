#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
struct Edge {
    int to, c, f;
    Edge* reverse;

    Edge() {
        to = 0;
        c = 0;
        f = 0;
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

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<Edge*> > adj(N + M + 3);
    auto makeEdge = [&](int n1, int n2, int cc) {
        auto e1 = new Edge();
        auto e2 = new Edge();

        e1 -> to = n2;
        e1 -> reverse = e2;
        e1 -> c = cc;
        e2 -> to = n1;
        e2 -> reverse = e1;

        adj[n1].push_back(e1);
        adj[n2].push_back(e2);
    };

    int S = 0, T = N + M + 1, X = N + M + 2;

    makeEdge(S, X, K);
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        makeEdge(S, i, 1);
        makeEdge(X, i, 1);
        while (num--) {
            int w;
            cin >> w;
            makeEdge(i, N + w, 1);
        }
    }
    for (int i = 1; i <= M; ++i) {
        makeEdge(N + i, T, 1);
    }

    while (true) {
        vector<Edge*> prev(N + M + 3, nullptr);
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            for (auto e: adj[f]) {
                if (e -> residual() <= 0) continue;
                if (prev[e -> to]) continue;
                q.push(e -> to);
                prev[e -> to] = e;
                if (e -> to == T) break;
            }
            if (prev[T]) break;
        }

        if (!prev[T]) break;

        int flow = 1e9;
        for (auto cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            flow = min(flow, prev[cur] -> residual());
        }
        for (auto cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            prev[cur] -> f += flow;
            prev[cur] -> reverse -> f -= flow;
        }
    }

    int answer = 0;
    for (auto e: adj[T]) {
        answer += e -> reverse -> f;
    }
    cout << answer << '\n';
}