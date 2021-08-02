#include <iostream>
#include <vector>
#include <queue>

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

    vector<vector<int> > visited(N, vector<int> (M, 987654321));
    queue<pair<int, int> > q;

    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [fr, fc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }

            if (!arr[nr][nc]) {
                continue;
            }

            if (visited[nr][nc] <= visited[fr][fc] + 1) {
                continue;
            }


            visited[nr][nc] = visited[fr][fc] + 1;
            if (nr == N - 1 && nc == M - 1) {
                cout << visited[nr][nc] << '\n';
                return 0;
            }
            q.push({nr, nc});
        }
    }
}