#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

#define N_MAX 20
#define INF 987654321
int N, M;
char arr[N_MAX][N_MAX] = {0};
int visited[N_MAX][N_MAX][N_MAX][N_MAX] = {0};

vector<pair<int, int> > coin;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int answer = INF;

bool outOfBoard(int r, int c) {
    return (r < 0 || r >= N || c < 0 || c >= M);
}

void bfs() {

    fill(&visited[0][0][0][0], &visited[0][0][0][0] + N_MAX * N_MAX * N_MAX * N_MAX, INF);

    queue<tuple<int, int, int, int> > q;
    visited[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = 0;
    q.push({coin[0].first, coin[0].second, coin[1].first, coin[1].second});

    while (!q.empty()) {
        auto [r1, c1, r2, c2] = q.front();
        q.pop();
        if (visited[r1][c1][r2][c2] == 10) {
            return;
        }

        for (int dir = 0; dir < 4; ++dir) {
            int nr1, nc1, nr2, nc2;

            nr1 = r1 + dr[dir];
            nc1 = c1 + dc[dir];
            nr2 = r2 + dr[dir];
            nc2 = c2 + dc[dir];

            if (outOfBoard(nr1, nc1) != outOfBoard(nr2, nc2)) {
                answer = min(answer, visited[r1][c1][r2][c2] + 1);
                return;
            }

            if (outOfBoard(nr1, nc1) && outOfBoard(nr2, nc2)) {
                continue;
            }

            if (arr[nr1][nc1] == '#') {
                nr1 -= dr[dir];
                nc1 -= dc[dir];
            }
            if (arr[nr2][nc2] == '#') {
                nr2 -= dr[dir];
                nc2 -= dc[dir];
            }

            if (visited[nr1][nc1][nr2][nc2] <= visited[r1][c1][r2][c2] + 1) {
                continue;
            }

            q.push({nr1, nc1, nr2, nc2});
            visited[nr1][nc1][nr2][nc2] = visited[r1][c1][r2][c2] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j) {
            arr[i][j] = s[j];
            if (arr[i][j] == 'o') {
                coin.push_back({i, j});
            }
        }
    }

    bfs();

    if (answer != INF) {
        cout  << answer << "\n";
    } else {
        cout << "-1\n";
    }
}