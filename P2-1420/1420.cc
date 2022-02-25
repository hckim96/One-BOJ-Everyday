#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

struct Edge {
    int to, c, f;
    Edge* reverse;
    Edge(int to_, int c_) {
        to = to_;
        c = c_;
        f = 0;
        reverse = nullptr;
    }

    int residual() {
        return c - f;
    }
};

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;
    vector<string> a(N);
    for (auto& e: a) {
        cin >> e;
    }

    vector<vector<Edge*> > adj(2 * N * M);
    auto makeEdge = [&](int u, int v) {
        auto e1 = new Edge(v, 1);
        auto e2 = new Edge(u, 0);
        e1 -> reverse = e2;
        e2 -> reverse = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    };

    int S, T;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (a[i][j] == '#') continue;

            if (a[i][j] == 'K') {
                S = 2 * (i * M + j) + 1;
            } else if (a[i][j] == 'H') {
                T = 2 * (i * M + j);
            }

            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + dr[dir];
                int nj = j + dc[dir];
                if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
                if (a[ni][nj] == '#') continue;
                makeEdge(2 * (i * M + j) + 1, 2 * (ni * M + nj));
            }
        }
    }
    for (int i = 0; i < N * M; ++i) {
        makeEdge(2 * i, 2 * i + 1);
    }

    if (abs(S / 2 / M - T / 2 / M) + abs(S / 2 % M - T / 2 % M) == 1) {
        cout << "-1\n";
        return 0;
    }

    int answer = 0;
    while (true) {
        vector<Edge*> prev(2 * N * M, nullptr);
        queue<int> q;
        q.push(S);

        while (q.size()) {
            auto f = q.front();
            q.pop();
            for (auto e: adj[f]) {
                if (prev[e -> to]) continue;
                if (e -> residual() <= 0) continue;

                prev[e -> to] = e;
                q.push(e -> to);
            }
        }

        if (!prev[T]) break;

        int flow = 1;
        answer += flow;
        for (auto cur = T; cur != S; cur = prev[cur] -> reverse -> to) {
            prev[cur] -> f += flow;
            prev[cur] -> reverse -> f -= flow;
        }
    }
    
    cout << answer << '\n';
}