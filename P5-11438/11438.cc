#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int findLCA(vector<vector<int> >& parent, vector<int>& depth, int a, int b, int kmax) {
    if (a == b) {
        return a;
    }

    int p1 = a;
    int p2 = b;
    if (depth[p1] < depth[p2]) {
        swap(p1, p2);
    }
    
    int diff = depth[p1] - depth[p2];

    int digit = 0;

    while (diff > 0) {
        if (diff & (1 << digit)) {
            p1 = parent[p1][digit];
            diff -= 1 << digit;
        }
        ++digit;
    }

    if (p1 == p2) {
        return p1;
    }

    for (int k = kmax; k >= 0; --k) {
        if (parent[p1][k] != -1 && parent[p1][k] != parent[p2][k]) {
            p1 = parent[p1][k];
            p2 = parent[p2][k];
        }
    }
    return parent[p1][0];
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > adj(N + 1, vector<int> ());
    int kmax = ceil(log2(N));

    vector<vector<int> > parent(N + 1, vector<int> (kmax + 1, -1));
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> depth(N + 1, INF);

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto e: adj[f]) {
            if (depth[e] == INF) {
                depth[e] = depth[f] + 1;
                parent[e][0] = f;
                q.push(e);
            }
        }
    }

    for (int k = 0; k < kmax; ++k) {
        for (int i = 1; i <= N; ++i) {
            if (parent[i][k] == -1) {
                continue;
            }
            parent[i][k + 1] = parent[parent[i][k]][k];
        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        cout << findLCA(parent, depth, a, b, kmax) << '\n';
    }
}