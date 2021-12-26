#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int M, N, K;
    cin >> M >> N >> K;
    vector<vector<int> > visited(N, vector<int> (M, false));

    while (K--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x2; --y2;
        for (int x = x1; x <= x2; ++x) {
            for (int y = y1; y <= y2; ++y) {
                visited[x][y] = true;
            }
        }
    }

    vector<int> answer;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!visited[i][j]) {
                int area = 0;

                queue<pair<int, int> > q;
                q.push({i, j});
                visited[i][j] = true;
                ++area;
                while (q.size()) {
                    auto [fr, fc] = q.front();
                    q.pop();
                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = fr + dr[dir];
                        int nc = fc + dc[dir];
                        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
                        if (visited[nr][nc]) continue;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                        ++area;
                    }
                }
                answer.push_back(area);
            }
        }
    }
    sort(all(answer));
    cout << answer.size() << '\n';
    for (auto e: answer) cout << e << ' ';
}