#include <iostream>
#include <queue>

using namespace std;

int N, M;
int answer = 0;

// 
int map[20][20];
// time visited.
int visited[20][20];

int sizeOfShark = 2;
int numOfEaten = 0;

int sharkR, sharkC;

int targetR, targetC, distToTarget;
// n e s w 
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<pair<int, int> > q;

void init() {
    targetR = 987654321;
    targetC = 987654321;
    distToTarget = 987654321;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = -1;
        }
    }
}

// 먹을 애 찾음.
void bfs(int sharkR, int sharkC) {
    init();

    visited[sharkR][sharkC] = 0;

    q.push({sharkR, sharkC});

    int frontR, frontC, nextR, nextC;

    while (!q.empty()) {
        frontR = q.front().first;
        frontC = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nextR = frontR + dr[i];
            nextC = frontC + dc[i];
            if (0 <= nextR && nextR < N && 0 <= nextC && nextC < N) {
                if (map[nextR][nextC] > sizeOfShark) {
                    continue;
                }
                if (visited[nextR][nextC] < 0) {
                    visited[nextR][nextC] = visited[frontR][frontC] + 1;
                    if (map[nextR][nextC] == sizeOfShark || map[nextR][nextC] == 0) {
                        // can pass
                        q.push({nextR, nextC});
                    } else if (map[nextR][nextC] < sizeOfShark) {
                        // can eat
                        if (distToTarget > visited[nextR][nextC]) {
                            targetR = nextR;
                            targetC = nextC;
                            distToTarget = visited[nextR][nextC];
                        } else if (distToTarget == visited[nextR][nextC]) {
                            if (targetR > nextR) {
                                targetR = nextR;
                                targetC = nextC;
                                distToTarget = visited[nextR][nextC];
                            } else if (targetR == nextR) {
                                if (targetC > nextC) {
                                    targetR = nextR;
                                    targetC = nextC;
                                    distToTarget = visited[nextR][nextC];
                                }
                            }
                        }
                        q.push({nextR, nextC});
                    }

                }
            }
        }

    }


}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                sharkR = i;
                sharkC = j;
                map[i][j] = 0;
            }
        }
    }


    while (true) {
        // find
        bfs(sharkR, sharkC);
        // if found  move shark
        // if not found , call mom
        if (distToTarget == 987654321) {
            break;
        } else {
            answer += distToTarget;
            map[targetR][targetC] = 0;
            sharkR = targetR;
            sharkC = targetC;
            numOfEaten++;
            if (numOfEaten == sizeOfShark) {
                numOfEaten = 0;
                sizeOfShark++;
            }
        }
    }
    cout << answer << "\n";

}