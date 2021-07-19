#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 2e9

int f(vector<vector<pair<int, int> > >& adj, vector<int>& distToOne, int cur, int leftEnergy) {
    if (cur == 1) {
        return cur;
    }

    for (auto [n, nw]: adj[cur]) {
        if (distToOne[cur] > distToOne[n] && leftEnergy >= nw) {
            return f(adj, distToOne, n, leftEnergy - nw);
        }
    }

    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> energy(N + 1);
    vector<vector<pair<int, int> > > adj(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> energy[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int n1, n2, w;

        cin >> n1 >> n2 >> w;

        adj[n1].push_back({n2, w});
        adj[n2].push_back({n1, w});
    }

    vector<int> distToOne(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    distToOne[1] = 0;
    pq.push({distToOne[1], 1});

    while (!pq.empty()) {
        auto [tw, t] = pq.top();
        pq.pop();

        if (tw > distToOne[t]) {
            continue;
        }

        for (auto [n, nw]: adj[t]) {
            if (distToOne[n] > distToOne[t] + nw) {
                distToOne[n] = distToOne[t] + nw;
                pq.push({distToOne[n], n});
            }
        }
    }   

    for (int i = 1; i <= N; ++i) {
        cout << f(adj, distToOne, i, energy[i]) << '\n';
    }
}
