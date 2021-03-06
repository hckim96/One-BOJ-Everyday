#include <iostream>
#include <queue>

using namespace std;

#define V_MAX 20000

int K, V, E;

vector<int> adjacencyList[V_MAX + 1];

int visited[V_MAX + 1];

void bfs(int start) {

    queue<int> q;
    int front;
    visited[start] = 1;
    q.push(start);

    while (!q.empty()) {
        front = q.front();
        q.pop();

        for (auto it = adjacencyList[front].begin(); it != adjacencyList[front].end(); it++) {
            if (visited[*it] != 0) {
                continue;
            }

            visited[*it] = -1 *visited[front];
            q.push(*it);
        }
    }
}

bool isBipartite() {
    for (int i = 1; i <= V; i++) {
        for (auto it = adjacencyList[i].begin(); it != adjacencyList[i].end(); it++) {
            if (visited[i] == visited[*it]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;

    while (K--) {
        fill_n(visited, V + 1, 0);

        cin >> V >> E;
        
        for (int i = 0; i < E; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            adjacencyList[n1].push_back(n2);
            adjacencyList[n2].push_back(n1);
        }

        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                bfs(i);
            }
        }

        if (isBipartite()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

        for (int i = 1; i <= V; i++) {
            adjacencyList[i].clear();
        }
    }
}