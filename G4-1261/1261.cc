#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 100

int N, M;
int map[N_MAX][N_MAX];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int cost[N_MAX][N_MAX];

void dijkstra() {
    
    // min-heap
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

    pq.push({0, 0, 0});
    cost[0][0] = 0;

    int weight, r, c, nr, nc;
    while (!pq.empty()) {
        tie(weight, r, c) = pq.top();
        pq.pop();

        for (int dir = 0; dir < 4; dir++) {
            nr = r + dr[dir];
            nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }

            if (cost[nr][nc] > cost[r][c] + map[nr][nc]) {
                cost[nr][nc] = cost[r][c] + map[nr][nc];
                pq.push({cost[nr][nc], nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            map[i][j] = tmp[j] - '0';    
        }
    }

    fill(&cost[0][0], &cost[N][M], 987654321);
    dijkstra();

    cout << cost[N - 1][M - 1] << "\n";
}