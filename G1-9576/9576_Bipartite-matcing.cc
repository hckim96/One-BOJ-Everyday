#include <iostream>
#include <vector>

using namespace std;

bool f(vector<pair<int, int> >& adj, vector<bool>& visited, vector<int>& B, int a) {
    for (int b = adj[a].first; b <= adj[a].second; ++b) {
        if (visited[b]) continue;
        visited[b] = true;
        if (!B[b] || f(adj, visited, B, B[b])) {
            B[b] = a;
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M;
        cin >> N >> M;
        
        vector<pair<int, int> > adj(M + 1);

        for (int i = 1; i <= M; ++i) {
            cin >> adj[i].first >> adj[i].second;
        }

        vector<int> B(N + 1, 0);
        vector<bool> visited(B.size(), false);

        int answer = 0;
        for (int i = 1; i <= M; ++i) {
            fill(visited.begin(), visited.end(), false);
            if (f(adj, visited, B, i)) {
                ++answer;
            }
        }
        cout << answer << '\n';
    }
}