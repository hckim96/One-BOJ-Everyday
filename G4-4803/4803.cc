#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    int caseCnt = 1;
    while (cin >> N >> M && (N || M)) {
        vector<vector<int> > adj(N + 1);

        while (M--) {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> visited(N + 1, 0);
        auto isTree = [&](int root) {
            queue<int> q;
            q.push(root);
            visited[root] = true;
            int edge = 0;
            int node = 0;
            while (q.size()) {
                auto f = q.front();
                q.pop();
                ++node;

                for (auto e: adj[f]) {
                    ++edge;
                    if (visited[e]) continue;
                    q.push(e);
                    visited[e] = true;
                }
            }
            return node * 2 - 2 == edge;
        };

        int treeCnt = 0;
        for (int i = 1; i <= N; ++i) {
            if (!visited[i]) {
                treeCnt += isTree(i);
            }
        }

        cout << "Case " << caseCnt++ << ": ";
        if (treeCnt == 0) {
            cout << "No trees.\n";
        } else if (treeCnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << treeCnt << " trees.\n";
        }
    }
}