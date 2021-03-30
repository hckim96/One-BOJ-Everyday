#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 987654321

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void moveCluster(vector<vector<char> >& arr, vector<vector<int> >& visited, int clusterIdx) {
    int fall = arr.size() - 1;

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            if (visited[i][j] == clusterIdx) {

                int nr = i + 1;

                while (nr < arr.size()) {
                    if (visited[nr][j] == clusterIdx) {
                        nr = INF;
                        break;
                    } 
                    
                    if (arr[nr][j] == 'x') {
                        break;
                    }

                    ++nr;
                }
                fall = min(fall, nr - i - 1);

            }
        }
    }
    for (int i = arr.size() - 1; i >= 0; --i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            if (visited[i][j] == clusterIdx) {
                arr[i][j] = '.';
                arr[i + fall][j] = 'x';
            }
        }
    }
}

bool isInTheAir(vector<vector<char> >& arr, vector<vector<int> >& visited, int r, int c, int clusterIdx) {
    queue<pair<int, int> > q;

    q.push({r, c});
    visited[r][c] = clusterIdx;
    bool ret = true;
    while (!q.empty()) {
        auto [fr, fc] = q.front();
        if (fr == arr.size() - 1) {
            ret = false;
        }
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr[0].size()) {
                continue;
            }

            if (arr[nr][nc] == '.') {
                continue;
            }

            if (visited[nr][nc]) {
                continue;
            }

            visited[nr][nc] = clusterIdx;
            q.push({nr, nc});
        }
    }

    return ret;
}

void throwStick(vector<vector<char> >& arr, int height, int dir) {
    int r, sc, v;
    r = arr.size() - height;
    if (dir) {
        sc = arr[0].size() - 1;
        v = -1;
    } else {
        sc = 0;
        v = 1;
    }
    int c = sc;
    while (c >= 0 && c < arr[0].size()) {

        if (arr[r][c] == 'x') {
            arr[r][c] = '.';

            int clusterIdx = 0;
            vector<vector<int> > visited(arr.size(), vector<int> (arr[0].size(), 0));
            for (int dd = 0; dd < 4; ++dd) {
                ++clusterIdx;
                int nr, nc;
                nr = r + dr[dd];
                nc = c + dc[dd];

                if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr[0].size()) {
                    continue;
                }
                if (arr[nr][nc] == '.') {
                    continue;
                }

                if (visited[nr][nc]) {
                    continue;
                }

                if (isInTheAir(arr, visited, nr, nc, clusterIdx)) {
                    moveCluster(arr, visited, clusterIdx);
                    break;
                }
            }
            break;
        }

        c += v;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<vector<char> > arr(R, vector<char> (C));

    for (int i = 0; i < R; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < C; ++j) {
            arr[i][j] = s[j];
        }
    }

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int h;
        cin >> h;

        throwStick(arr, h, i % 2);
    }

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = 0; j < arr[0].size(); ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
