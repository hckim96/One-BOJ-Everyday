#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define N_MAX 1000

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int N, M;

int map[N_MAX + 1][N_MAX + 1] = {0};
int visited[N_MAX + 1][N_MAX + 1][2] = {0};

void bfs() {

    int frontR, frontC, breakCnt, nextR, nextC;
    queue<tuple<int, int, int> > q;

    q.push({1, 1, 0});
    visited[1][1][0] = 1;

    while (!q.empty()) {
        tie(frontR, frontC, breakCnt) = q.front();
        // cout << "bfs(" << frontR << ", " << frontC << ", " << breakCnt << ")\n";
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            nextR = frontR + dr[dir];
            nextC = frontC + dc[dir];

            if (nextR < 1 || nextR > N || nextC < 1 || nextC > M) {
                continue;
            }

            if (map[frontR][frontC] == 1) {
                if (breakCnt == 0) {
                    if (visited[nextR][nextC][breakCnt + 1] == -1) {
                        visited[nextR][nextC][breakCnt + 1] = visited[frontR][frontC][breakCnt] + 1;
                        q.push({nextR, nextC, breakCnt + 1});
                    }
                }
            } else {
                if (visited[nextR][nextC][breakCnt] == -1) {
                    visited[nextR][nextC][breakCnt] = visited[frontR][frontC][breakCnt] + 1;
                    q.push({nextR, nextC, breakCnt});
                }
            }

            if (visited[N][M][0] != -1 || visited[N][M][1] != -1) {
                return;
            }

        }
    }
}


int main() {
    cin >> N >> M;
    fill(&visited[0][0][0], &visited[0][0][0] + (2 * (N_MAX + 1) * (N_MAX + 1)), - 1);
    
    
    for (int i = 1; i <= N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= M; j++) {
            map[i][j] = tmp[j - 1] - '0';
        }
    }

    bfs();
    
    // bfs 후에 둘다 -1 이거나 하나만 -1이 아닌 상태 이므로 답은 max 로

    cout << max(visited[N][M][0], visited[N][M][1]) << "\n";

}