#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 100

int answer = 0;
int adjacency[N_MAX + 1][N_MAX + 1] = {0};
int N, M;

void bfs() {
    queue<int> q;

    bool visited[N_MAX + 1] = {0};

    visited[1] = true;
    q.push(1);

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        
        for (int i = 1; i <= N; i++) {
            if (adjacency[front][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
                answer++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adjacency[a][b] = adjacency[b][a] = 1;
    }
    
    bfs();

    cout << answer << "\n";
}