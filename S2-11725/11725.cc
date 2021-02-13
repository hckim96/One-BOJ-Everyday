#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > adjacency (N + 1, vector<int> ());

    for (int i = 0; i < N - 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;

        adjacency[n1].push_back(n2);
        adjacency[n2].push_back(n1);
    }

    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(1);
    visited[1] = true;

    vector<int> parent(N + 1, 0);

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (auto v: adjacency[f]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = f;
                q.push(v);
            }
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << parent[i] << '\n';
    }
}
