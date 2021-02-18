#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X;

    cin >> N >> M >> X;
    
    vector<vector<pair<int, int> > > edge(N + 1, vector<pair<int, int> > ());
    vector<vector<pair<int, int> > > edge2(N + 1, vector<pair<int, int> > ());

    vector<int> dist(N + 1, INF);
    vector<int> dist2(N + 1, INF);


    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge2[b].push_back({a, c});
    }


    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[X] = 0;
    pq.push({dist[X], X});

    while (!pq.empty()) {
        auto [c, n] = pq.top();
        pq.pop();
        if (c > dist[n]) {
            continue;
        }

        for (auto e: edge[n]) {
            if (dist[e.first] > dist[n] + e.second) {
                dist[e.first] = dist[n] + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }
    
    dist2[X] = 0;
    pq.push({dist2[X], X});

    while (!pq.empty()) {
        auto [c, n] = pq.top();
        pq.pop();
        if (c > dist2[n]) {
            continue;
        }

        for (auto e: edge2[n]) {
            if (dist2[e.first] > dist2[n] + e.second) {
                dist2[e.first] = dist2[n] + e.second;
                pq.push({dist2[e.first], e.first});
            }
        }
    }


    int answer = 0;

    for (int i = 1; i <= N; ++i) {
        answer = max(answer, dist[i] + dist2[i]);
    }

    cout << answer << '\n';
}