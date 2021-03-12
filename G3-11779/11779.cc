#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int> > > cost(N + 1, vector<pair<int, int> > ());

    for (int i = 0; i < M; ++i) {
        int a, b, c;

        cin >> a >> b >> c;
        cost[a].push_back({b, c});
    }

    int S, E;
    cin >> S >> E;

    vector<int> dist(N + 1, INF);
    vector<int> prev(N + 1, 0);

    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({dist[S], S});

    while (!pq.empty()) {
        auto [tc, tn] = pq.top();
        pq.pop();

        if (tc > dist[tn]) {
            continue;
        }

        for (auto e: cost[tn]) {
            if (dist[e.first] > dist[tn] + e.second) {
                dist[e.first] = dist[tn] + e.second;
                prev[e.first] = tn;
                pq.push({dist[e.first], e.first});
            }
        }
    }

    cout << dist[E] << '\n';

    int cnt = 0;
    string answer;
    while (E) {
        ++cnt;
        answer = to_string(E) + ' ' + answer;
        E = prev[E];
    }
    cout << cnt << '\n';
    cout << answer << '\n';
}