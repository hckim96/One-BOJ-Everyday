#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define N_MAX 50
#define INF 987654321

vector<pair<int, int> > virus;
vector<pair<int, int> > active(10);
bool isActive[N_MAX][N_MAX] = {0};
int map[N_MAX][N_MAX] = {0};
int N, M;
int g_air = 0;

int answer = INF;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int spreadVirus() {
    int air = g_air;
    queue<pair<int, int> > q;
    int visited[N_MAX][N_MAX] = {0};

    if (air == 0) {
        return 1;
    }

    for (int i = 0; i < M; i++) {
        q.push(active[i]);    
        visited[active[i].first][active[i].second] = 1;
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
                continue;
            } 
            if (visited[nr][nc] >= 1) {
                continue;
            }
            if (map[nr][nc] == 1) {
                continue;
            }
            q.push({nr, nc});
            visited[nr][nc] = visited[r][c] + 1;

            if (map[nr][nc] == 0) {
                air--;
                if (air == 0) {
                    return visited[nr][nc];
                }
                if (visited[nr][nc] >= answer) {
                    return INF;
                }
            }
        }
    }
    return INF;
}

void select(int idx, int selected, int virusCnt) {

    if (selected == M) {
        answer = min(answer, spreadVirus());
        return;
    }

    if (idx >= virusCnt) {
        return;
    }

    select(idx + 1, selected, virusCnt);
    active[selected] = virus[idx];
    isActive[active[selected].first][active[selected].second] = true;
    select(idx + 1, selected + 1, virusCnt);
    isActive[active[selected].first][active[selected].second] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back({i, j});
            } else if (map[i][j] == 0) {
                g_air++;
            }
        }
    }

    int virusCnt = virus.size();
    select(0, 0, virusCnt);

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer - 1 << "\n";
    }
}