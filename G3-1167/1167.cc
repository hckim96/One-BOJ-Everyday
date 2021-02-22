#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;
    
    vector<vector<pair<int, int> > > edge(V + 1, vector<pair<int, int> > ());

    int v1, v2, w;

    for (int i = 0; i < V; ++i) {
        cin >> v1;
        while (true) {
            cin >> v2;
            if (v2 == -1) {
                break;
            }
            cin >> w;

            edge[v1].push_back({v2, w});
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> dist(V + 1, INF);

    int maxDist, maxDistV;
    dist[1] = 0;
    maxDist = 0;
    maxDistV = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [tw, tv] = pq.top();
        pq.pop();

        if (tw > dist[tv]) {
            continue;
        }

        for (auto e: edge[tv]) {
            if (dist[e.first] > tw + e.second) {
                dist[e.first] = tw + e.second;
                pq.push({dist[e.first], e.first});
                if (maxDist < dist[e.first]) {
                    maxDist = dist[e.first];
                    maxDistV = e.first;
                }
            }
        }
    }

    fill(dist.begin(), dist.end(), INF);

    dist[maxDistV] = 0;
    maxDist = 0;
    pq.push({0, maxDistV});

    while (!pq.empty()) {
        auto [tw, tv] = pq.top();
        pq.pop();

        if (tw > dist[tv]) {
            continue;
        }

        for (auto e: edge[tv]) {
            if (dist[e.first] > tw + e.second) {
                dist[e.first] = tw + e.second;
                pq.push({dist[e.first], e.first});
                if (maxDist < dist[e.first]) {
                    maxDist = dist[e.first];
                }
            }
        }
    }
    
    cout << maxDist << '\n';
}