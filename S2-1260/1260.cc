#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void f(vector<vector<int> >& adj, vector<bool>& visited, int cur) {
    visited[cur] = true;
    cout << cur << ' ';
    for (auto e: adj[cur]) {
        if (!visited[e]) {
            f(adj, visited, e);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    vector<bool> visited(N + 1, false);
    vector<vector<int> > adj(N + 1);
    
    while (M--) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    f(adj, visited, V);
    cout << '\n';

    queue<int> q;
    fill(visited.begin(), visited.end(), false);

    q.push(V);
    visited[V] = true;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        cout << f << ' ';
        for (auto e: adj[f]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = true;
            }
        }
    }
    cout << '\n';
}