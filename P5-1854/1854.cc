#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int START = 1;

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<pair<int, int> > > adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<priority_queue<int> > dist(N + 1);

    dist[START].push(0);
    pq.push({dist[START].top(), START});

    while (!pq.empty()) {
        auto [d, n] = pq.top();
        pq.pop();

        if (d > dist[n].top()) {
            continue;
        }

        for (auto [next, weight]: adj[n]) {
            if (dist[next].size() < K) {
                dist[next].push(d + weight);
                pq.push({d + weight, next});
            } else {
                if (dist[next].top() > d + weight) {
                    dist[next].pop();
                    dist[next].push(d + weight);
                    pq.push({d + weight, next});
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (dist[i].size() == K) {
            cout << dist[i].top() << '\n';
        } else {
            cout << "-1\n";
        }
    }
}