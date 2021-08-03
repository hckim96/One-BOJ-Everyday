#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > arr(N, vector<int> (N, 0));
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }
    
    vector<vector<bool> > visited(N, vector<bool> (N, false));
    queue<pair<int, int> > q;

    vector<int> answer;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (arr[i][j] == 1 && visited[i][j] == 0) {
                q.push({i, j});
                visited[i][j] = true;
                int cnt = 1;
                while (!q.empty()) {
                    auto [fr, fc] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = fr + dr[dir];
                        int nc = fc + dc[dir];

                        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                            continue;
                        }

                        if (arr[nr][nc] == 0 || visited[nr][nc]) {
                            continue;
                        }

                        visited[nr][nc] = true;
                        q.push({nr, nc});
                        ++cnt;
                    }
                }
                answer.push_back(cnt);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (auto e: answer) {
        cout << e << '\n';
    }
}