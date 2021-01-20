#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 1000

int N, M;
int arr[N_MAX + 1][N_MAX + 1] = {0};
int visited[N_MAX + 1] = {0};

void bfs(int n) {

    queue<int> q;

    visited[n] = 1;
    q.push(n);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && arr[front][i]) {
                visited[i] = 1;
                q.push(i);
            }    
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        arr[u][v] = arr[v][u] = 1;
    }
    
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            bfs(i);
            answer++;
        }
    }

    cout << answer << "\n";
}