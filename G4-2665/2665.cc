#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 50
#define INF 987654321

int N;
int arr[N_MAX][N_MAX] = {0}; // 0 : white, 1 : black
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
vector<vector<int> > cost(N_MAX, vector<int> (N_MAX, INF));

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

    cost[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        auto [w, r, c] = pq.top();
        pq.pop();

        if (w > cost[r][c]) {
            continue;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }

            if (w + arr[nr][nc] < cost[nr][nc]) {
                cost[nr][nc] = w + arr[nr][nc];
                pq.push({cost[nr][nc], nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            arr[i][j] = ((tmp[j] - '0') == 0) ? 1 : 0;
        }
    }

    dijkstra();

    cout << cost[N - 1][N - 1] << "\n";
}
