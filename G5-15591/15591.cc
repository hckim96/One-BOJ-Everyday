#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f(vector<vector<pair<int, int> > >& adj, int k, int v) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);

    q.push(v);
    visited[v] = true;

    int ret = 0;
    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (auto [n, r]: adj[f]) {
            if (visited[n]) {
                continue;
            }

            if (r < k) {
                visited[n] = true;
                continue;
            }
            
            q.push(n);
            visited[n] = true;
            ++ret;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;

    vector<vector<pair<int, int> > > adj(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int p, q, r;
        cin >> p >> q >> r;

        adj[p].push_back({q, r});
        adj[q].push_back({p, r});
    }

    while (Q--) {
        int k, v;
        cin >> k >> v;

        cout << f(adj, k, v) << '\n';
    }
}