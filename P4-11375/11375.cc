#include <iostream>
#include <vector>

using namespace std;

bool f(vector<vector<int> >& adj, vector<bool>& visited, vector<int>& A, vector<int>& B, int n) {
    visited[n] = true;
    for (auto m: adj[n]) {
        if (!B[m] || (!visited[B[m]] && f(adj, visited, A, B, B[m]))) {
            A[n] = m;
            B[m] = n;
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

    vector<int> A(N + 1, 0);
    vector<int> B(M + 1, 0);
    vector<vector<int> > adj(N + 1);

    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        while(cnt--) {
            int m;
            cin >> m;
            adj[i].push_back(m);
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        vector<bool> visited(A.size(), false);
        if (f(adj, visited, A, B, i)) {
            ++answer;
        }
    }

    cout << answer << '\n';
}