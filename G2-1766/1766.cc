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
        int n1, n2;
        cin >> n1 >> n2;

        arr[n1].push_back(n2);
        ++indegree[n2];
    }

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        auto f = pq.top();
        pq.pop();

        cout << f << ' ';

        for (auto e: arr[f]) {
            --indegree[e];
            if (indegree[e] == 0) {
                pq.push(e);
            }
        }
    }
    cout << '\n';
}
