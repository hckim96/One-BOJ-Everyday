#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    vector<vector<int> > arr(N, vector<int> (M, 0));

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    vector<vector<bool> > visited(N, vector<bool> (M, false));
    vector<int> zeroNumOfGroup(N * M, 0);
    vector<vector<int> > groupOfCoord(N, vector<int> (M, 0));

    int curGroup = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j] && !arr[i][j]) {
                int cnt = 0;
                ++curGroup;
                queue<pair<int, int> > q;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    auto [fr, fc] = q.front();
                    q.pop();
                    groupOfCoord[fr][fc] = curGroup;
                    ++cnt;

                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = fr + dr[dir];
                        int nc = fc + dc[dir];

                        if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                            continue;
                        }
                        if (visited[nr][nc]) {
                            continue;
                        }
                        if (arr[nr][nc]) {
                            continue;
                        }
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
                zeroNumOfGroup[curGroup] = cnt;
            }
        }
    }

    vector<string> answer(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!arr[i][j]) {
                answer[i].push_back('0');
            } else {
                int tmp = 1;
                set<int> group;

                for (int dir = 0; dir < 4; ++dir) {
                    int nr = i + dr[dir];
                    int nc = j + dc[dir];
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                        continue;
                    }
                    if (arr[nr][nc]) {
                        continue;
                    }
                    group.insert(groupOfCoord[nr][nc]);
                }

                for (auto e: group) {
                    tmp += zeroNumOfGroup[e];
                }

                answer[i] += to_string(tmp % 10);
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << answer[i] << '\n';
    }
}
