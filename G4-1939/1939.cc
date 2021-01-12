#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define N_MAX 10000

int N, M;
vector<pair<int, int> > bridge[N_MAX + 1];

// weight 으로 dest 도착 가능하면 true
bool bfs(int start, int dest, int weight) {

    bool visited[N_MAX + 1] = {0};
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int front = q.front();
        if (front == dest) {
            return true;
        }
        q.pop();

        for (auto it = bridge[front].begin(); it != bridge[front].end(); it++) {
            if (visited[it -> first]) {
                continue;
            }

            if (it -> second >= weight) {
                q.push(it -> first);
                visited[it -> first] = true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    int bridgeWeightMax = 0;
    for (int i = 0; i < M; i++) {
        int A, B, C;

        cin >> A >> B >> C;

        bridgeWeightMax = max(bridgeWeightMax, C);

        bridge[A].push_back({B, C});
        bridge[B].push_back({A, C});
    }

    int start, destination;
    cin >> start >> destination;

    // binary search
    int low, high;
    low = 0;
    high = bridgeWeightMax;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (bfs(start, destination, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << high << "\n";
}