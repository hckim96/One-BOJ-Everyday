#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 125

int map[N_MAX][N_MAX];
int N;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int dist[N_MAX][N_MAX] = {0};


// same with greater<>
struct cmp {
    bool operator() (tuple<int, int, int> t1, tuple<int, int, int> t2) {
        return get<0>(t1) > get<0>(t2);
    }
};

void dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, cmp > pq;

    dist[0][0] = map[0][0];
    pq.push({dist[0][0], 0, 0});

    while (!pq.empty()) {
        auto [w, r, c] = pq.top();
        pq.pop();

        if (w > dist[r][c]) {
            continue;
        }
        
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            }

            if (dist[nr][nc] > map[nr][nc] + dist[r][c]) {
                dist[nr][nc] = map[nr][nc] + dist[r][c];
                pq.push({dist[nr][nc], nr, nc});
            }
        }    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    while (true) {
        cin >> N;
        if (N == 0) {
            return 0;
        }

        fill(&dist[0][0], &dist[0][0] + N_MAX * N_MAX, 987654321);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }

        dijkstra();

        cout << "Problem " << T++ << ": " << dist[N - 1][N - 1] << "\n";
    }
}