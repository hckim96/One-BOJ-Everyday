#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, H;
    cin >> N >> M >> H;
    
    // r, c, dir
    vector<vector<vector<int> > > holeHeight(N, vector<vector<int> > (M, vector<int> (4, H)));
    vector<vector<int> > water(N, vector<int> (M, H));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < M; ++j) {
            int num;
            cin >> num;
            if (num == -1) continue;

            if (i == 0) {
                holeHeight[i][j][0] = num;
                water[i][j] = min(water[i][j], num);
                pq.push({water[i][j], i, j});
            } else if (i == N) {
                holeHeight[i - 1][j][2] = num;
                water[i - 1][j] = min(water[i - 1][j], num);
                pq.push({water[i - 1][j], i - 1 , j});
            } else {
                holeHeight[i][j][0] = holeHeight[i - 1][j][2] = num;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            int num;
            cin >> num;
            if (num == -1) continue;

            if (j == 0) {
                holeHeight[i][j][3] = num;
                water[i][j] = min(water[i][j], num);
                pq.push({water[i][j], i, j});
            } else if (j == M) {
                holeHeight[i][j - 1][1] = num;
                water[i][j - 1] = min(water[i][j - 1], num);
                pq.push({water[i][j - 1], i, j - 1});
            } else {
                holeHeight[i][j][3] = holeHeight[i][j - 1][1] = num;
            }
        }
    }

    while (!pq.empty()) {
        auto [w, r, c] = pq.top();
        pq.pop();

        if (w > water[r][c]) continue;

        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (holeHeight[r][c][dir] == H) continue;

            if (water[nr][nc] > max(water[r][c], holeHeight[r][c][dir])) {
                water[nr][nc] = max(water[r][c], holeHeight[r][c][dir]);
                pq.push({water[nr][nc], nr, nc});
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            answer += water[i][j];
        }
    }
    cout << answer << '\n';
}