#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;

vector<int> dijkstra(vector<vector<pair<int, int> > >& adj, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(adj.size(), INF);
    dist[S] = 0;
    pq.push({dist[S], S});
    
    while (!pq.empty()) {
        auto [d, n] = pq.top();
        pq.pop();

        if (d > dist[n]) {
            continue;
        }

        for (auto [nn, nw]: adj[n]) {
            if (dist[nn] > d + nw) {
                dist[nn] = d + nw;
                pq.push({dist[nn], nn});
            }
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M, T, S, G, H;
        cin >> N >> M >> T >> S >> G >> H;

        vector<vector<pair<int, int> > > adj(N + 1);

        int GHLen;
        for (int i = 0; i < M; ++i) {
            int a, b, d;
            cin >> a >> b >> d;

            if ((a == G && b == H) || (a == H && b == G)) {
                GHLen = d;
            }
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }


        vector<int> v(T);
        for (int i = 0; i < T; ++i) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        auto distS = dijkstra(adj, S);
        int closerPoint = distS[G] > distS[H] ? H : G;
        int nextCloserPoint = closerPoint == H ? G : H;
        auto dist2 = dijkstra(adj, nextCloserPoint);

        for (auto e: v) {
            if (distS[e] == distS[closerPoint] + GHLen + dist2[e]) {
                cout << e << ' ';
            }
        }
        cout << '\n';
    }
}