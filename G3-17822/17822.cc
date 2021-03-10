#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int N, M, T;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void rotate(vector<vector<int> >& arr,int x, int d, int k) {
    vector<vector<int> > tmp(arr);
    int kk = k;
    if (d == 1) {
        kk = M - kk;
    }

    for (int i = x; i <= N; i += x) {
        for (int j = 1; j <= M; ++j) {
            arr[i][(j - 1 + kk) % M + 1] = tmp[i][j];
        }
    }

    return;
}

void update(vector<vector<int> >& arr) {
    int cnt = 0;

    vector<vector<bool> > visited(N + 1, vector<bool> (M + 1, false));
    queue<pair<int, int> > q;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (arr[i][j] != INF && !visited[i][j]) {
                bool shouldRemove = false;
                for (int dir = 0; dir < 4; ++dir) {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];

                    if (nr < 1 || nr > N) {
                        continue;
                    }

                    if (nc == 0) {
                        nc = M;
                    }
                    if (nc == M + 1) {
                        nc = 1;
                    }

                    if (arr[i][j] == arr[nr][nc]) {
                        shouldRemove = true;
                        break;
                    }
                }

                if (shouldRemove) {
                    ++cnt;

                    int num = arr[i][j];
                    arr[i][j] = INF;
                    visited[i][j] = true;
                    q.push({i, j});
                    
                    while (!q.empty()) {
                        auto [fr, fc] = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; ++dir) {
                            int nr = fr + dr[dir];
                            int nc = fc + dc[dir];

                            if (nr < 1 || nr > N) {
                                continue;
                            }

                            if (nc == 0) {
                                nc = M;
                            }
                            if (nc == M + 1) {
                                nc = 1;
                            }

                            if (visited[nr][nc]) {
                                continue;
                            }
                            
                            if (arr[nr][nc] != num) {
                                continue;
                            }

                            q.push({nr, nc});
                            arr[nr][nc] = INF;
                            visited[nr][nc] = true;
                        }
                    }
                }
            }
            
        }
    }

    if (!cnt) {
        double average = 0;
        double totalSum = 0;
        double totalCnt = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (arr[i][j] != INF) {
                    ++totalCnt;
                    totalSum += arr[i][j];
                }
            }
        }

        average = totalSum / totalCnt;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (arr[i][j] != INF) {
                    if (arr[i][j] > average) {
                        --arr[i][j];
                    } else if (arr[i][j] < average) {
                        ++arr[i][j];
                    }
                }
            }
        }
    }

    return;
}

int sum(vector<vector<int> >& arr) {
    int ret = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (arr[i][j] != INF) {
                ret += arr[i][j];
            }
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> T;

    vector<vector<int> > arr(N + 1, vector<int> (M + 1, INF));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }

    while (T--) {
        int x, d, k;
        cin >> x >> d >> k;

        rotate(arr, x, d, k);
        update(arr);
    }

    cout << sum(arr) << '\n';
}
