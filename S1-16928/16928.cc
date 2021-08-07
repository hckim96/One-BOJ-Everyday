#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // [u] = v
    vector<int> move(101, 0);
    int cnt = N + M;

    while (cnt --) {
        int x, y;
        cin >> x >> y;
        move[x] = y;
    }

    vector<int> visited(101, 987654321);
    queue<int> q;

    visited[1] = 0;
    q.push(1);

    while (!q.empty()) {
        auto f = q.front();
        q.pop();

        for (int i = 1; i <= 6; ++i) {
            int n = f + i;

            if (n > 100) {
                break;
            }

            if (move[n]) {
                n = move[n];
            }

            if (visited[n] <= visited[f] + 1) {
                continue;
            }

            visited[n] = visited[f] + 1;

            if (n == 100) {
                cout << visited[n] << '\n';
                return 0;
            }
            q.push(n);
        }
    }
}