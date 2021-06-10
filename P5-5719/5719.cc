#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    while (N || M) {
        int S, D;
        cin >> S >> D;

        vector<vector<pair<int, int> > > adj(N);

        int u, v, p;
        for (int i = 0; i < M; ++i) {
            cin >> u >> v >> p;

            adj[u].push_back({v, p});
        }

        vector<int> dist(N, INF);
        vector<vector<int> > prev(N);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        dist[S] = 0;
        pq.push({dist[S], S});

        while (!pq.empty()) {
            auto [td, tn] = pq.top();
            pq.pop();

            if (td > dist[tn]) {
                continue;
            }
            
            for (auto [n, d]: adj[tn]) {

                if (dist[n] > dist[tn] + d) {
                    dist[n] = dist[tn] + d;
                    pq.push({dist[n], n});
                    prev[n].clear();
                    prev[n].push_back(tn);
                } else if (dist[n] == dist[tn] + d) {
                    prev[n].push_back(tn);
                }
            }
        }

        queue<int> q;
        q.push(D);

        while (!q.empty()) {
            auto f = q.front();
            q.pop();

            for (auto e: prev[f]) {
                for (auto it = adj[e].begin(); it != adj[e].end(); ++it) {
                    if (it -> first == f) {
                        adj[e].erase(it);
                        q.push(e);
                        break;
                    }
                }
            }
        }        
        
        fill(dist.begin(), dist.end(), INF);
        dist[S] = 0;
        pq.push({dist[S], S});

        while (!pq.empty()) {
            auto [td, tn] = pq.top();
            pq.pop();

            if (td > dist[tn]) {
                continue;
            }
            
            for (auto [n, d]: adj[tn]) {
                if (dist[n] > dist[tn] + d) {
                    dist[n] = dist[tn] + d;
                    pq.push({dist[n], n});
                }
            }
        }

        if (dist[D] == INF) {
            cout << "-1\n";
        } else {
            cout << dist[D] << '\n';
        }

        cin >> N >> M;
    }
}
