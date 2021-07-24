#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f(vector<vector<int> >& adj, int start) {
    vector<bool> visited(adj.size());
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int ret = 1;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (auto e: adj[f]) {
            if (!visited[e]) {
                q.push(e);
                visited[e] = true;
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > adj(N + 1);

    while (M--) {
        int A, B;
        cin >> A >> B;
        adj[B].push_back(A);
    }

    vector<int> answer;
    int maxNum = 0;
    for (int i = 1; i <= N; ++i) {
        int num = f(adj, i);

        if (maxNum > num) {
            continue;
        }

        if (maxNum < num) {
            maxNum = num;
            answer.clear();
        }

        answer.push_back(i);
    }

    for (auto e: answer) {
        cout << e << ' ';
    }
    cout << '\n';
}