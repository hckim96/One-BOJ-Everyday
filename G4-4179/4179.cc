#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define COORD_MAX 1000
#define INF 987654321
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int R, C;
char map[COORD_MAX][COORD_MAX] = {0};
int answer = INF;

vector<vector<int> > fireVisited(COORD_MAX, vector<int> (COORD_MAX, INF));
queue<pair<int ,int> > fireQ;
vector<vector<int> > JihunVisited(COORD_MAX, vector<int> (COORD_MAX, INF));
queue<pair<int, int> > JihunQ;

void fireBFS() {
    while (!fireQ.empty()) {
        auto [fr, fc] = fireQ.front();
        fireQ.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }
            if (map[nr][nc] == '#') {
                continue;
            }
            if (fireVisited[nr][nc] <= fireVisited[fr][fc] + 1) {
                continue;
            }

            fireVisited[nr][nc] = fireVisited[fr][fc] + 1;
            fireQ.push({nr, nc});
        }
    }
}

void JihunBFS() {
    while (!JihunQ.empty()) {
        auto [fr, fc] = JihunQ.front();
        JihunQ.pop();

        if (fr == 0 || fr == R - 1 || fc == 0 || fc == C - 1) {
            answer = answer > JihunVisited[fr][fc] + 1 ? JihunVisited[fr][fc] + 1 : answer;
            return;
        }
        for (int dir = 0; dir < 4; dir++) {
            int nr = fr + dr[dir];
            int nc = fc + dc[dir];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }
            if (map[nr][nc] == '#') {
                continue;
            }
            if (JihunVisited[nr][nc] != INF) {
                continue;
            }
            if (fireVisited[nr][nc] <= JihunVisited[fr][fc] + 1) {
                continue;
            }

            JihunVisited[nr][nc] = JihunVisited[fr][fc] + 1;
            JihunQ.push({nr, nc});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'J') {
                JihunQ.push({i, j});
                JihunVisited[i][j] = 0;
            } else if (map[i][j] == 'F') {
                fireQ.push({i, j});
                fireVisited[i][j] = 0;
            }
        }
    }

    fireBFS();
    JihunBFS();

    if (answer == INF) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << answer << "\n";
    }
}