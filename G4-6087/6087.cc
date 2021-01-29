#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 100
#define INF 987654321

int N, M;
char map[N_MAX][N_MAX] = {0};
vector<vector<vector<int> > > visited(N_MAX, vector<vector<int> > (N_MAX, vector<int> (N_MAX, INF)));
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;

    int SR, SC, TR, TC;
    SR = -1;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j];
            if (map[i][j] == 'C') {
                if (SR == -1) {
                    SR = i;
                    SC = j;
                } else {
                    TR = i;
                    TC = j;
                }
            }
        }
    }
    
    // BFS
    queue<tuple<int, int, int> > q;

    int tmpR, tmpC, tmpD;
    for (int dir = 0; dir < 4; dir++) {
        tmpR = SR;
        tmpC = SC;
        tmpD = dir;

        while (tmpR >= 0 && tmpR < N && tmpC >= 0 && tmpC < M && map[tmpR][tmpC] != '*') {
            visited[tmpR][tmpC][tmpD] = 0;
            q.push({tmpR, tmpC, tmpD});
            tmpR += dr[tmpD];
            tmpC += dc[tmpD];
        }

    }

    while (!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr, nc, nd, cost;

            if (dir == (d + 2) % 4) {
                continue;
            }

            if (dir == d) {
                nr = r + dr[d];
                nc = c + dc[d];
                nd = d;
                cost = 0;
                while (nr >= 0 && nr < N && nc >= 0 && nc < M && map[nr][nc] != '*' && visited[nr][nc][nd] > visited[r][c][d] + cost) {
                    visited[nr][nc][nd] = visited[r][c][d] + cost;
                    q.push({nr, nc, nd});
                    nr += dr[nd];
                    nc += dc[nd];
                }
            } else {
                nr = r;
                nc = c;
                nd = dir;
                cost = 1;

                if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                    continue;
                }

                if (map[nr][nc] == '*') {
                    continue;
                }

                if (visited[nr][nc][nd] <= visited[r][c][d] + cost) {
                    continue;
                }

                visited[nr][nc][nd] = visited[r][c][d] + cost;
                q.push({nr, nc, nd});
            }
        }
    }

    int answer = 2 * INF;

    for (int dir = 0; dir < 4; dir++) {
        if (answer > visited[TR][TC][dir]) {
            answer = visited[TR][TC][dir];
        }
    }
    cout << answer << "\n";
}