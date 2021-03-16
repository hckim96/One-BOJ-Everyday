#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define INF 987654321

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int> > arr(N + 1, vector<int> (M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; ++j) {
            arr[i][j] = s[j - 1] - '0';
        }
    }

    vector<vector<vector<int> > > visited(N + 1, vector<vector<int> > (M + 1, vector<int> (K + 1, INF)));
    visited[1][1][0] = 1;

    queue<tuple<int, int, int> > q;

    q.push({1, 1, 0});
    int answer = INF;

    while (!q.empty()) {
        auto [fr, fc, fk] = q.front();
        if (fr == N && fc == M) {
            answer = visited[fr][fc][fk];
            break;
        }
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 1 || nr > N || nc < 1 || nc > M) {
                continue;
            }

            int nk = fk + arr[nr][nc];
            if (nk > K) {
                continue;
            }

            if (visited[nr][nc][nk] <= visited[fr][fc][fk] + 1) {
                continue;
            }

            visited[nr][nc][nk] = visited[fr][fc][fk] + 1;
            q.push({nr, nc, nk});
        }
    }

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }
}
