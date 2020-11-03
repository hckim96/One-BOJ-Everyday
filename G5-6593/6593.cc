#include <iostream>
#include <string>
#include <tuple>
#include <queue>

using namespace std;

int L, R, C;

// l r c
char map[30][30][30];


int visited[30][30][30] = {0};
tuple<int, int, int> start, goal;

int dl[6] = {1, -1, 0, 0, 0, 0};
int dr[6] = {0, 0, 1, -1, 0, 0};
int dc[6] = {0, 0, 0, 0, 1, -1};

int answer = -1;

void bfs() {

    int startL, startR, startC, frontL, frontR, frontC, nextL, nextR, nextC;

    tie(startL, startR, startC) = start;

    queue<tuple<int, int, int> > q;

    q.push({startL, startR, startC});
    visited[startL][startR][startC] = 0;


    while (!q.empty()) {
        tie(frontL, frontR, frontC) = q.front();
        q.pop();

        for (int dir = 0; dir < 6; dir++) {
            tie(nextL, nextR, nextC) = make_tuple(frontL + dl[dir], frontR + dr[dir], frontC + dc[dir]);

            if (nextL < 0 || nextL >= L || nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) {
                continue;
            }
            if (map[nextL][nextR][nextC] == '#') {
                continue;
            }
            if (visited[nextL][nextR][nextC] >= 0) {
                continue;
            }

            q.push({nextL, nextR, nextC});
            visited[nextL][nextR][nextC] = visited[frontL][frontR][frontC] + 1;
        }

        if (visited[get<0>(goal)][get<1>(goal)][get<2>(goal)] != -1) {
            answer = visited[get<0>(goal)][get<1>(goal)][get<2>(goal)];
            break;
        }
    }
}

int main() {
    string tmp;
    while (true) {
        answer = -1;
        cin >> L >> R >> C;

        if (L == 0) {
            break;
        }

        getline(cin, tmp);
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                getline(cin, tmp);
                for (int k = 0; k < C; k++) {
                    map[i][j][k] = tmp[k];
                    visited[i][j][k] = -1;
                    if (map[i][j][k] == 'S') {
                        start = {i, j, k};
                    } else if (map[i][j][k] == 'E') {
                        goal = {i, j, k};
                    }
                }
            }
            getline(cin, tmp);
        }

        bfs();
        
        if (answer != -1) {
            cout << "Escaped in " << answer <<" minute(s).";
        } else {
            cout << "Trapped!";
        }
        cout << "\n";
    }
}