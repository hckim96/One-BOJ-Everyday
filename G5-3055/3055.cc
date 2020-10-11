#include <iostream>
#include <queue>

using namespace std;

int R, C;

// 0, 1, 2, 3, 4  빔 물 돌 굴, 고
int map[50][50];

// time when water in the position start : 0
int waterMap[50][50];
int dooMap[50][50];
int answer = 987654321;
queue<pair<int, int> > water, doo;
int GoR,GoC;
// 북 동 남 서 
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int DR, DC;
int main() {
    cin >> R >> C;
    char tmp;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            waterMap[i][j] = 987654321;
            dooMap[i][j] = 987654321;
            cin >> tmp;
            switch (tmp) {
                case '.':
                //empty
                    map[i][j] = 0;
                    break;
                case '*':
                // water
                    map[i][j] = 1;
                    water.push({i, j});
                    waterMap[i][j] = 0;
                    break;
                case 'X':
                // rock
                    map[i][j] = 2;
                    break;
                case 'D':
                // gool
                    map[i][j] = 3;
                    DR = i;
                    DC = j;
                    break;
                case 'S':
                    map[i][j] = 4;
                    doo.push({i,j});
                    dooMap[i][j] = 0;
                    GoR = i;
                    GoC = j;
                    break;
                default:
                    return 1;
                    break;
            }
        }
    }

    while (!water.empty()) {
        int waterR = water.front().first;
        int waterC = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = waterR + dr[i];
            int nextC = waterC + dc[i];
            if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C  && waterMap[nextR][nextC] > waterMap[waterR][waterC] + 1) {
                if (map[nextR][nextC] == 0 || map[nextR][nextC] == 4) {
                    waterMap[nextR][nextC] = waterMap[waterR][waterC] + 1;
                    water.push({nextR, nextC});
                }
            }
        }
    }
    while (!doo.empty()) {
        int dooR = doo.front().first;
        int dooC = doo.front().second;
        doo.pop();

        for (int i = 0; i < 4; i++) {
            int nextR = dooR + dr[i];
            int nextC = dooC + dc[i];
            if (nextR >= 0 && nextR < R && nextC >= 0 && nextC < C) {
                if (waterMap[nextR][nextC] > 1 + dooMap[dooR][dooC]) {

                    if (map[nextR][nextC] == 3) {
                        dooMap[nextR][nextC] = min(dooMap[dooR][dooC] + 1, dooMap[nextR][nextC]);
                        while (!doo.empty()) {
                            doo.pop();
                        }
                        break;
                    }
                    if (map[nextR][nextC] == 0 || map[nextR][nextC] == 4) {
                        if (dooMap[nextR][nextC] > dooMap[dooR][dooC] + 1) {
                            dooMap[nextR][nextC] = dooMap[dooR][dooC] + 1;
                            doo.push({nextR, nextC});

                        }
                    }
                }
            }
        }
    }

    if (dooMap[DR][DC] == 987654321) {
        cout << "KAKTUS\n";
    } else {
        cout << dooMap[DR][DC] << "\n";
    }
}