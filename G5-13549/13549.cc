#include <iostream>
#include <queue>

using namespace std;

int N, K;

int cost[100001];

void bfs() {
    for (int i = 0; i <= 100000; i++) {
        cost[i] = -1;
    }

    queue<int> q;
    q.push(N);
    cost[N] = 0;

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        if (i != 0) {
            int j = i;
            while (2 * j <= 100000 && cost[2 * j] == -1) {
                cost[2 * j] = cost[j];
                q.push(2 * j);
                j = j * 2;
            }
        }

        if (i + 1 <= 100000 && cost[i + 1] == -1) {
            cost[i + 1] = cost[i] + 1;
            q.push(i + 1);
        }

        if (i - 1 >= 0 && cost[i - 1] == -1) {
            cost[i - 1] = cost[i] + 1;
            q.push(i - 1);
        }

        if (cost[K] != -1) {
            break;
        }
    }

}

int main() {
    cin >> N >> K;

    bfs();

    cout << cost[K] << "\n";
}