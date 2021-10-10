#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    const int INF = 1e9;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, n1, n2;
    cin >> n >> n1 >> n2;

    vector<vector<int> > adj(n + 1);

    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    vector<int> visited(n + 1, INF);
    queue<int> q;

    q.push(n1);
    visited[n1] = 0;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        if (f == n2) {
            break;
        }

        for (auto e: adj[f]) {
            if (visited[e] <= visited[f] + 1) continue;
            q.push(e);
            visited[e] = visited[f] + 1;
        }
    }

    if (visited[n2] == INF) {
        cout << "-1\n";
    } else {
        cout << visited[n2] << '\n';
    }
}