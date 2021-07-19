#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> energy(N + 1);
    vector<vector<pair<int, int> > > adj(N + 1);

    int kmax = 0;
    int tmp = 1;

    while (tmp < N - 1) {
        tmp <<= 1;
        kmax += 1;
    }

    vector<vector<int> > parent(N + 1, vector<int> (kmax + 1, 0));

    for (int i = 1; i <= N; ++i) {
        cin >> energy[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int n1, n2, w;

        cin >> n1 >> n2 >> w;

        adj[n1].push_back({n2, w});
        adj[n2].push_back({n1, w});

    }

    queue<pair<int, int> > q;
    vector<bool> visited(N + 1, false);
    vector<int> dist(N + 1, 0);

    q.push({1, dist[1]});
    visited[1] = true;

    while (!q.empty()) {
        auto [f, fw] = q.front();
        q.pop();

        for (auto [n, nw]: adj[f]) {
            if (!visited[n]) {
                visited[n] = true;
                parent[n][0] = f;
                dist[n] = fw + nw;
                q.push({n, dist[n]});
            }
        }
    }

    for (int k = 1; k <= kmax; ++k) {
        for (int n = 1; n <= N; ++n) {
            parent[n][k] = parent[parent[n][k - 1]][k - 1];
        }
    }

    for (int i = 1; i <= N; ++i) {
        int answer = i;
        int leftEnergy = energy[i];

        for (int k = kmax; k >= 0; --k) {
            if (parent[answer][k] && leftEnergy >= dist[answer] - dist[parent[answer][k]]) {
                leftEnergy -= dist[answer] - dist[parent[answer][k]];
                answer = parent[answer][k];
            }
        }
        cout << answer << '\n';
    }
}
