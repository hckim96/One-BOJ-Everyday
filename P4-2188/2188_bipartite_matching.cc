#include <iostream>
#include <vector>

using namespace std;

bool f(vector<vector<int> >& adj, vector<bool>& visited, vector<int>& A, vector<int>& B, int n) {
    visited[n] = true;

    for (auto e: adj[n]) {
        if (B[e] == -1 || (!visited[B[e]] && f(adj, visited, A, B, B[e]))) {
            A[n] = e;
            B[e] = n;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<int> A(N + 1, -1);
    vector<int> B(M + 1, -1);
    vector<vector<int> > adj(N + 1);

    for (int i = 1; i <= N; ++i) {
        int S;
        cin >> S;
        while (S--) {
            int n;
            cin >> n;
            adj[i].push_back(n);
        }
    }

    vector<bool> visited(N + 1, false);

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        fill(visited.begin(), visited.end(), false);
        if (f(adj,  visited, A, B, i)) {
            ++answer;
        }
    }

    cout << answer << '\n';
}