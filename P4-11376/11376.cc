#include <iostream>
#include <vector>

using namespace std;

bool f(vector<vector<int> >& adj, vector<bool>& visited, vector<int>& A, vector<int>& B, int a) {
    visited[a] = true;
    for (auto b: adj[a]) {
        if (!B[b] || (!visited[B[b]] && f(adj, visited, A, B, B[b]))) {
            B[b] = a;
            A[a] = b;
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

    vector<vector<int> > adj(max(3 * N - 1, 3 * M) + 1);
    vector<int> A(3 * N, 0);
    vector<int> B(3 * M + 1, 0);
    vector<bool> visited(A.size(), false);
    
    for (int i = 1; i <= N; ++i) {
        int cnt;
        cin >> cnt;
        
        while (cnt--) {
            int num;
            cin >> num;
            adj[3 * i - 2].push_back(3 * num);
            adj[3 * i - 1].push_back(3 * num);
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        fill(visited.begin(), visited.end(), false);
        if (f(adj, visited, A, B, 3 * i - 2)) {
            ++answer;
        }
        fill(visited.begin(), visited.end(), false);
        if (f(adj, visited, A, B, 3 * i - 1)) {
            ++answer;
        }
    }
    cout << answer << '\n';
}