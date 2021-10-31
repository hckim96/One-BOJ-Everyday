#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int> > p(N + 1), c(N + 1);

    while (M--) {
        int u, v;
        cin >> u >> v;

        p[v].push_back(u);
        c[u].push_back(v);
    }

    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(X);
    visited[X] = true;
    int U = 1;
    while (q.size()) {
        auto f = q.front();
        q.pop();
        for (auto e: p[f]) {
            if (visited[e]) continue;
            ++U;
            q.push(e);
            visited[e] = true;
        }
    }
    q.push(X);
    visited[X] = true;
    int V = N;
    while (q.size()) {
        auto f = q.front();
        q.pop();
        for (auto e: c[f]) {
            if (visited[e]) continue;
            --V;
            q.push(e);
            visited[e] = true;
        }
    }

    cout << U << ' ' << V << '\n';
}