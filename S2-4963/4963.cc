#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int C, R;
    while (cin >> C >> R && C && R) {
        vector<vector<int> > v(R, vector<int> (C, false));

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> v[i][j];
            }
        }

        vector<vector<int> > visited(R, vector<int> (C, false));
        int answer = 0;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (v[i][j] && !visited[i][j]) {
                    ++answer;

                    queue<pair<int, int> > q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while (q.size()) {
                        auto [fr, fc] = q.front();
                        q.pop();

                        for (int dir = 0; dir < 8; ++dir) {
                            int nr = fr + dr[dir];
                            int nc = fc + dc[dir];
                            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                            if (visited[nr][nc]) continue;
                            if (!v[nr][nc]) continue;

                            visited[nr][nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }

        cout << answer << '\n';
    }
}