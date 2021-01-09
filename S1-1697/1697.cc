#include <iostream>
#include <queue>

using namespace std;

#define N_MAX 100000

vector<int> visited(2 * N_MAX + 1, -1);

int N, K;

void bfs() {
    queue<int> q;

    q.push(N);
    visited[N] = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == K) {
            return;
        }

        int next;
        for (int i = -1; i < 2; i++) {
            if (i == 0) {
                next = front << 1;
            } else {
                next = front + i;
            }

            if (next < 0 || next >= max(2 * K, N)) {
                continue;
            }
            if (visited[next] != -1) {
                continue;
            }
            q.push(next);
            visited[next] = visited[front] + 1;
        }
    }
}

int main() {
    cin >> N >> K;

    bfs();

    cout << visited[K] << "\n";
}