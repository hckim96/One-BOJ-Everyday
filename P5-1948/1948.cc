#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int S, E;
int answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int> > > adj(N + 1);
    vector<vector<pair<int, int> > > adj_rev(N + 1);
    vector<int> indegree_rev(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int n1, n2, t;
        cin >> n1 >> n2 >> t;

        adj[n1].push_back({n2, t});
        adj_rev[n2].push_back({n1, t});
        ++indegree_rev[n1];
    }

    cin >> S >> E;

    vector<int> maxTimeToDest(N + 1, 0);
    queue<int> q_rev;
    q_rev.push(E);

    while (!q_rev.empty()) {
        auto f = q_rev.front();
        q_rev.pop();

        for (auto e: adj_rev[f]) {
            maxTimeToDest[e.first] = max(maxTimeToDest[e.first], maxTimeToDest[f] + e.second);
            if (--indegree_rev[e.first] == 0) {
                q_rev.push(e.first);
            }
        }
    }

    vector<bool> visited(N + 1, false);

    queue<int> q;

    q.push(S);
    visited[S] = true;

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (auto [next, cost]: adj[f]) {
            if (maxTimeToDest[f] == maxTimeToDest[next] + cost) {
                ++answer;
                
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }
    
    cout << maxTimeToDest[S] << '\n';
    cout << answer << '\n';
}
