#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define INF 987654321

// 나이트, 비숍, 룩
vector<vector<int> > dr = {
    {1, 2, 1, 2, -1, -2, -1, -2},
    {1, 1, -1, -1},
    {0, 0, 1, -1}
};

vector<vector<int> > dc = {
    {2, 1, -2, -1, 2, 1, -2, -1},
    {1, -1, 1, -1},
    {1, -1, 0, 0}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > arr(N, vector<int> (N));
    pair<int, int> onePos;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                onePos = {i, j};
            }
        }
    }

    queue<tuple<int, int, int, int> > q;
    vector<vector<vector<vector<int> > > > visited(3, vector<vector<vector<int> > > (N, vector<vector<int> > (N, vector<int> (N * N + 2, INF))));

    for (int kind = 0; kind < 3; ++kind) {
        q.push({kind, onePos.first, onePos.second, 2});
        visited[kind][onePos.first][onePos.second][2] = 0;
    }

    while (!q.empty()) {
        auto [k, i, j, t] = q.front();
        q.pop();

        // change dir
        for (int nk = 0; nk < 3; ++nk) {
            if (nk == k) {
                continue;
            }
            if (visited[nk][i][j][t] > visited[k][i][j][t] + 1) {
                visited[nk][i][j][t] = visited[k][i][j][t] + 1;
                q.push({nk, i, j, t});
            }
        }

        // move

        // 비 룩 : 나이트 
        int tmpMax = k ? N - 1 : 1;
        int dirMax = k ? 4 : dr[k].size();

        for (int dir = 0; dir < dirMax; ++dir) {
            for (int tmp = 1; tmp <= tmpMax; ++tmp) {
                int nk = k;
                int ni = i + dr[k][dir] * tmp;
                int nj = j + dc[k][dir] * tmp;
                int nt;

                if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                    break;
                }

                nt = arr[ni][nj] == t ? t + 1 : t;

                if (visited[nk][ni][nj][nt] <= visited[k][i][j][t] + 1) {
                    continue;
                }

                visited[nk][ni][nj][nt] = visited[k][i][j][t] + 1;
                if (nt == N * N + 1) {
                    cout << visited[nk][ni][nj][nt] << '\n';
                    return 0;
                }
                q.push({nk, ni, nj, nt});
            }
        }
    }
}