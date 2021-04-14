#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr(N + 1, vector<int> ());
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        ++indegree[b];
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        cout << f << ' ';

        for (auto e: arr[f]) {
            --indegree[e];
            if (indegree[e] == 0) {
                q.push(e);
            }
        }
    }

    cout << '\n';
}