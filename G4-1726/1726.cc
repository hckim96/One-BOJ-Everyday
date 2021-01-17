#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 100

int N, M;
int arr[N_MAX][N_MAX] = {0};

// 동 남 서 북
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int sr, sc, sd;
int tr, tc, td;

// r, c, direction
vector<vector<vector<int> > > visited(N_MAX, vector<vector<int > > (N_MAX, vector<int> (4, -1)));

void bfs() {

    queue<tuple<int, int, int> > q;

    q.push({sr, sc, sd});
    visited[sr][sc][sd] = 0;

    while (!q.empty()) {
        auto [fr, fc, fd] = q.front();
        q.pop();

        if (visited[tr][tc][td] > -1) {
            return;
        }
        int nr, nc, nd;
        
        // go k
        for (int k = 1; k <= 3; k++) {
            nr = fr + dr[fd] * k;
            nc = fc + dc[fd] * k;
            nd = fd;

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                continue;
            }
            if (visited[nr][nc][nd] > -1) {
                continue;
            }
            if (arr[nr][nc] == 1) {
                // 중간 막혀있으면 직진 더이상 못함
                break;
            }


            q.push({nr, nc, nd});
            visited[nr][nc][nd] = visited[fr][fc][fd] + 1;
        }

        // change dir
        for (int dir = 0; dir < 2; dir++){
            nr = fr;
            nc = fc;
            if (dir == 0) {
                // left
                nd = (fd + 3) % 4;
            } else if (dir == 1) {
                // right
                nd = (fd + 1) % 4;
            }

            if (visited[nr][nc][nd] > -1) {
                continue;
            }


            q.push({nr, nc, nd});
            visited[nr][nc][nd] = visited[fr][fc][fd] + 1;
        }
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cin >> sr >> sc >> sd;
    cin >> tr >> tc >> td;
    sr--; sc--; tr--; tc--;
    switch (sd) {
        case 1:
            sd = 0;
            break;
        case 2:
            sd = 2;
            break;
        case 3:
            sd = 1;
            break;
        case 4:
            sd = 3;
            break;
    }
    switch (td) {
        case 1:
            td = 0;
            break;
        case 2:
            td = 2;
            break;
        case 3:
            td = 1;
            break;
        case 4:
            td = 3;
            break;
    }

    bfs();

    cout << visited[tr][tc][td] << "\n";
}