#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int> > arr(N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int> > q;
    vector<vector<bool> > visited(N, vector<bool> (M, false));
    int islandCnt = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] && !visited[i][j]) {
                ++islandCnt;

                q.push({i, j});
                arr[i][j] = islandCnt;
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [fr, fc] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = fr + dr[dir];
                        int nc = fc + dc[dir];

                        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                            continue;
                        }

                        if (!arr[nr][nc] || visited[nr][nc]) {
                            continue;
                        }

                        arr[nr][nc] = islandCnt;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

    vector<vector<int> > adj(islandCnt + 1, vector<int> (islandCnt + 1, INF));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j]) {
                for (int dir = 0; dir < 4; ++dir) {
                    int ni, nj;
                    int bridgeLen = 0;
                    for (int k = 1; k <= 9; ++k) {
                        ni = i + dr[dir] * k;
                        nj = j + dc[dir] * k;

                        if (ni < 0 || ni >= N || nj < 0 || nj >= M) {
                            break;
                        }

                        if (arr[ni][nj]) {
                            if (arr[i][j] == arr[ni][nj]) {
                                bridgeLen = 0;
                            } else {
                                int n1 = arr[i][j];
                                int n2 = arr[ni][nj];
                                
                                if (bridgeLen > 1) {
                                    adj[n1][n2] = adj[n2][n1] = min(adj[n1][n2], bridgeLen);
                                }
                                break;
                            }
                        } else {
                            ++bridgeLen;
                        }
                    }
                }
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<bool> mstSet(islandCnt + 1, false);

    int mstSetSize = 0;
    pq.push({0, 1});

    int answer = 0;
    while (!pq.empty() && mstSetSize != islandCnt) {
        auto [c, n] = pq.top();
        pq.pop();

        if (mstSet[n]) {
            continue;
        }

        answer += c;
        mstSet[n] = true;
        ++mstSetSize;

        for (int i = 1; i <= islandCnt; ++i) {
            if (adj[n][i] == INF) {
                continue;
            }

            if (mstSet[i]) {
                continue;
            }

            pq.push({adj[n][i], i});
        }
    }

    if (mstSetSize == islandCnt) {
        cout << answer << '\n';
    } else {
        cout << "-1\n";
    }
}