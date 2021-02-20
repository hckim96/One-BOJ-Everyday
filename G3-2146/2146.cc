#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > arr(N, vector<int> (N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int> > section(N, vector<int> (N, 0));

    int sectionNum = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] != 0 && section[i][j] == 0) {
                ++sectionNum;

                queue<pair<int, int> > q;
                q.push({i, j});
                section[i][j] = sectionNum;
                while (!q.empty()) {
                    auto [fr, fc] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = fr + dr[dir];
                        int nc = fc + dc[dir];

                        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                            continue;
                        }

                        if (arr[nr][nc] == 0) {
                            continue;
                        }
                        if (section[nr][nc] != 0) {
                            continue;
                        }

                        section[nr][nc] = sectionNum;
                        q.push({nr, nc});
                    }
                }

            }
        }
    }
    int answer = INF;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (section[i][j]) {
                int startSection = section[i][j];

                queue<pair<int, int> > q;
                vector<vector<int> > visited(N, vector<int> (N, INF));

                q.push({i, j});
                visited[i][j] = 0;

                while (!q.empty()) {
                    auto [fr, fc] = q.front();
                    q.pop();
                    
                    if (answer == visited[fr][fc]) {
                        break;
                    }

                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = fr + dr[dir];
                        int nc = fc + dc[dir];

                        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                            continue;
                        }

                        if (arr[nr][nc] == 1 && section[nr][nc] != startSection) {
                            answer = min(answer, visited[fr][fc]);
                            while (!q.empty()) {
                                q.pop();
                            }
                            break;
                        }

                        if (visited[nr][nc] <= visited[fr][fc] + 1) {
                            continue;
                        }

                        if (arr[nr][nc] != 0) {
                            continue;
                        }

                        q.push({nr, nc});
                        visited[nr][nc] = visited[fr][fc] + 1;
                    }
                }

                
            }
        }
    }

    cout << answer << '\n';
}