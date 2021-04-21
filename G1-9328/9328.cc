#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int H, W;
        cin >> H >> W;

        vector<vector<char> > arr(H + 2, vector<char> (W + 2, '.'));


        for (int i = 0; i < H; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < W; ++j) {
                arr[i + 1][j + 1] = s[j];
            }
        }

        string s;
        cin >> s;

        vector<bool> hasKey(26, false);
        if (s[0] != '0') {
            for (auto e: s) {
                hasKey[e - 'a'] = true;
            }
        }

        vector<vector<pair<int, int> > > doorCoord(26, vector<pair<int, int> > ());

        queue<pair<int, int> > q;
        vector<vector<bool> > visited(H + 2, vector<bool> (W + 2, false));
        q.push({0, 0});
        visited[0][0] = true;

        int answer = 0;

        while (!q.empty()) {
            auto [fr, fc] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir) {
                int nr = fr + dr[dir];
                int nc = fc + dc[dir];

                if (nr < 0 || nr >= H + 2 || nc < 0 || nc >= W + 2) {
                    continue;
                }

                if (visited[nr][nc]) {
                    continue;
                }

                if (arr[nr][nc] == '*') {
                    continue;
                }

                if (arr[nr][nc] >= 'A' && arr[nr][nc] <= 'Z' && !hasKey[arr[nr][nc] - 'A']) {
                    doorCoord[arr[nr][nc] - 'A'].push_back({nr, nc});
                    continue;
                }

                if (arr[nr][nc] >= 'a' && arr[nr][nc] <= 'z') {
                    if (!hasKey[arr[nr][nc] - 'a']) {
                        hasKey[arr[nr][nc] - 'a'] = true;

                        for (auto e: doorCoord[arr[nr][nc] - 'a']) {
                            q.push(e);
                            visited[e.first][e.second] = true;
                        }
                        doorCoord[arr[nr][nc] - 'a'].clear();
                    }
                }

                if (arr[nr][nc] == '$') {
                    ++answer;
                }

                q.push({nr, nc});
                visited[nr][nc] = true;

            }
        }
        
        cout << answer << '\n';

    }
}