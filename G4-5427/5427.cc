#include <iostream>
#include <queue>

using namespace std;

#define W_MAX 1000

int T, W, H;
char map[W_MAX][W_MAX];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

queue<pair<int, int> > fire;
int fireVisited[W_MAX][W_MAX] = {0};

queue<pair<int, int> > q;
int visited[W_MAX][W_MAX];

int answer = -1;

void fireBfs() {
    
    while (!fire.empty()) {
        auto [r, c] = fire.front();
        fire.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                continue;
            }

            if (map[nr][nc] == '#') {
                continue;
            }

            if (fireVisited[nr][nc] != -1 && fireVisited[nr][nc] <= fireVisited[r][c] + 1) {
                continue;
            }

            fire.push({nr, nc});
            fireVisited[nr][nc] = fireVisited[r][c] + 1;
        }
    }
}

void SangGeunBfs() {
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == 0 || r == H - 1 || c == 0 || c == W - 1) {
            answer = visited[r][c] + 1;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (map[nr][nc] == '#') {
                continue;
            }

            if (visited[nr][nc] > 0) {
                continue;
            }

            if (fireVisited[nr][nc] != -1 && fireVisited[nr][nc] <= visited[r][c] + 1) {
                continue;
            }

            q.push({nr, nc});
            visited[nr][nc] = visited[r][c] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> W >> H;

        fill(&fireVisited[0][0], &fireVisited[W_MAX - 1][W_MAX - 1], -1);
        fill(&visited[0][0], &visited[W_MAX - 1][W_MAX - 1], -1);
        if (!fire.empty()) {
            queue<pair<int, int> > tmpQ;
            swap(fire, tmpQ);
        }
        if (!q.empty()) {
            queue<pair<int, int> > tmpQ;
            swap(q, tmpQ);
        }

        answer = -1;

        for (int i = 0; i < H; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < W; j++) {
                map[i][j] = tmp[j];
                if (map[i][j] == '*') {
                    fire.push({i, j});
                    fireVisited[i][j] = 0;
                } else if (map[i][j] == '@') {
                    q.push({i, j});
                    visited[i][j] = 0;
                }
            }
        }

        fireBfs();
        SangGeunBfs();

        if (answer == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << answer << "\n";
        }
    }
}