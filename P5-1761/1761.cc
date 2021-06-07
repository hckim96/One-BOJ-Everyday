#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

int findLCA(vector<vector<int> >& parent, vector<int>& depth, int n1, int n2) {

    if (depth[n1] < depth[n2]) {
        swap(n1, n2);
    }

    int diff = depth[n1] - depth[n2];

    int digit = 0;
    while (diff > 0) {
        if (diff & (1 << digit)) {
            n1 = parent[n1][digit];
            diff -= (1 << digit);
        }
        ++digit;
    }

    if (n1 == n2) {
        return n1;
    }

    int kmax = parent[0].size() - 1;

    for (int k = kmax; k >= 0; --k) {
        if (parent[n1][k] != -1 && parent[n1][k] != parent[n2][k]) {
            n1 = parent[n1][k];
            n2 = parent[n2][k];
        }
    }

    return parent[n1][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<pair<int, int> > > arr(N + 1, vector<pair<int, int> > ());

    for (int i = 0; i < N - 1; ++i) {
        int n1, n2, d;
        cin >> n1 >> n2 >> d;

        arr[n1].push_back({n2, d});
        arr[n2].push_back({n1, d});
    }

    vector<vector<int> > parent(N + 1, vector<int> (ceil(log2(N)) + 1, -1));
    vector<int> depth(N + 1, -1);
    vector<int> dist(N + 1, -1);


    depth[1] = 0;
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (auto e: arr[f]) {
            if (depth[e.first] == -1) {
                depth[e.first] = depth[f] + 1;
                parent[e.first][0] = f;
                dist[e.first] = dist[f] + e.second;
                q.push(e.first);
            }
        }
    }

    for (int k = 0; k < parent[0].size(); ++k) {
        for (int n = 1; n <= N; ++n) {
            if (parent[n][k] == -1) {
                continue;
            }

            parent[n][k + 1] = parent[parent[n][k]][k];
        }
    }

    int M;
    cin >> M;

    while (M--) {
        int n1, n2;
        cin >> n1 >> n2;

        cout << dist[n1] + dist[n2] - 2 * dist[findLCA(parent, depth, n1, n2)] << '\n';
    }
}
