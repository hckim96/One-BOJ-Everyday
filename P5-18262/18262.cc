#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<tuple<int, int, int> > > adj(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b, c, f;
        cin >> a >> b >> c >> f;
        adj[a].push_back({b, c, f});
        adj[b].push_back({a, c, f});
    }  

    priority_queue<tuple<int, int, int> > pq;
    vector<vector<int> > minCost(N + 1, vector<int> (1001, INF));

    minCost[1][1000] = 0;
    pq.push({-minCost[1][1000], 1, 1000});

    double ret = 0;
    while (!pq.empty()) {
        auto [c, n, f] = pq.top();
        c *= -1;
        pq.pop();

        if (c > minCost[n][f]) continue;

        if (n == N) {
            ret = max(ret, (double)f / c);
            continue;
        }

        for (auto [nn, nc, nf]: adj[n]) {
            nf = min(nf, f);
            if (minCost[nn][nf]> c + nc) {
                minCost[nn][nf] = c + nc;
                pq.push({-minCost[nn][nf], nn, nf});
            }
        }
    }

    cout << int(1e6 * ret) << '\n';
}