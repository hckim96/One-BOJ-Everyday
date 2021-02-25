#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int findLCA(vector<int>& parent, vector<int>& depth, int a, int b) {
    int p1 = a;
    int p2 = b;

    if (depth[p1] < depth[p2]) {
        swap(p1, p2);
    }
    
    while (depth[p1] != depth[p2]) {
        p1 = parent[p1];
    }

    while (p1 != p2) {
        p1 = parent[p1];
        p2 = parent[p2];
    }

    return p1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > adj(N + 1, vector<int> ());
    vector<int> parent(N + 1, -1);
    vector<int> degree(N + 1, 0);
    vector<int> depth(N + 1, INF);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++degree[a];
        ++degree[b];
    }

    queue<int> q;

    for (int i = 2; i <= N; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        if (f == 1) {
            continue;
        }

        int p;
        
        for (auto e: adj[f]) {
            if (parent[e] == -1) {
                p = e;
                break;
            }
        }
        parent[f] = p;

        --degree[p];
        if (degree[p] == 1) {
            q.push(p);
        }
    }
    
    q.push(1);
    depth[1] = 0;
    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto i: adj[f]) {
            if (parent[i] == f) {
                depth[i] = depth[f] + 1;
                q.push(i);
            }

        }
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        cout << findLCA(parent, depth, a, b) << "\n";
    }
}