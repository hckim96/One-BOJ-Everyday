#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<vector<int> > a(N, vector<int> (N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }

    long long answer = 0;
    for (int h = 0; h <= 100; ++h) {
        vector<vector<int> > visited(N, vector<int> (N, false));
        long long cnt = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (a[i][j] > h && !visited[i][j]) {
                    queue<pair<int, int> > q;
                    visited[i][j] = true;
                    q.push({i, j});
                    ++cnt;

                    while (q.size()) {
                        auto [fr, fc] = q.front();
                        q.pop();

                        for (int dir = 0; dir < 4; ++dir) {
                            int nr = fr + dr[dir];
                            int nc = fc + dc[dir];
                            if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
                            if (visited[nr][nc]) continue;
                            if (a[nr][nc] <= h) continue;
                            q.push({nr, nc});
                            visited[nr][nc] = true;
                        }
                    }
                }
            }
        }

        answer = max(answer, cnt);
    }
    cout << answer << '\n';
}