#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 800
#define INF 987654321

int N, E;
int map[N_MAX + 1][N_MAX + 1] = {0};

int dijkstra(int start, int stop1, int stop2, int end) {
    int distance[N_MAX + 1];
    priority_queue<pair<int, int> , vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // 두가지 경로 거리 start stop1 stop2 end , start stop2 stop1 end
    int path[2][3] = {0};

    // from stop1
    fill_n(distance, N_MAX + 1, INF);
    
    distance[stop1] = 0;
    pq.push({distance[stop1], stop1});

    while (!pq.empty()) {
        auto [d, nodeNum] = pq.top();
        pq.pop();

        if (d > distance[nodeNum]) {
            continue;
        }
        for (int i = 1; i <= N; i++) {
            if (map[nodeNum][i] == 0) {
                continue;
            }

            if (distance[i] > distance[nodeNum] + map[nodeNum][i]) {
                distance[i] = distance[nodeNum] + map[nodeNum][i];
                pq.push({distance[i], i});
            }
        }
    }

    path[0][0] = distance[start];
    path[0][1] = distance[stop2];
    path[1][1] = distance[stop2];
    path[1][2] = distance[end];

    // from stop2
    fill_n(distance, N_MAX + 1, INF);

    distance[stop2] = 0;
    pq.push({distance[stop2], stop2});

    while (!pq.empty()) {
        auto [d, nodeNum] = pq.top();
        pq.pop();

        if (d > distance[nodeNum]) {
            continue;
        }
        for (int i = 1; i <= N; i++) {
            if (map[nodeNum][i] == 0) {
                continue;
            }

            if (distance[i] > distance[nodeNum] + map[nodeNum][i]) {
                distance[i] = distance[nodeNum] + map[nodeNum][i];
                pq.push({distance[i], i});
            }
        }
    }

    path[0][2] = distance[end];
    path[1][0] = distance[1];

    int sum[2] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            if (path[i][j] == INF) {
                sum[i] = -1;
                break;
            } else {
                sum[i] += path[i][j];
            }
        }
    }

    if (sum[0] == -1 || sum[1] == -1) {
        return max(sum[0], sum[1]);
    } else {
        return min(sum[0], sum[1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    int v1, v2;

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        map[a][b] = map[b][a] = c;
    }
    cin >> v1 >> v2;

    cout << dijkstra(1, v1, v2, N) << "\n";
}