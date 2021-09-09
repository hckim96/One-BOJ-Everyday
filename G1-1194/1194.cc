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
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<string> arr(N);

    int sr, sc;
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == '0') {
                sr = i;
                sc = j;
            }
        }
    }

    queue<tuple<int, int, int> > q;
    vector<vector<vector<int> > > visited(N, vector<vector<int> > (M, vector<int> (1 << ('F' - 'A' + 1), INF)));

    visited[sr][sc][0] = 0;
    q.push({sr, sc, 0});

    while (!q.empty()) {
        auto [fr, fc, fKey] = q.front();
        q.pop();

        if (arr[fr][fc] == '1') {
            cout << visited[fr][fc][fKey] << '\n';
            return 0;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];
            int nKey = fKey;

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }

            if (arr[nr][nc] == '#') {
                continue;
            }
            
            if ('A' <= arr[nr][nc] && arr[nr][nc] <= 'F' && !(nKey & (1 << (arr[nr][nc] - 'A')))) {
                continue;
            }

            if ('a' <= arr[nr][nc] && arr[nr][nc] <= 'f') {
                nKey |= (1 << (arr[nr][nc] - 'a'));
            }

            if (visited[nr][nc][nKey] <= visited[fr][fc][fKey] + 1) {
                continue;
            }

            q.push({nr, nc, nKey});
            visited[nr][nc][nKey] = visited[fr][fc][fKey] + 1;
        }
    }

    cout << "-1\n";
}