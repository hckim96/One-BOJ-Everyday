#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define N 4

int answer = 0;

int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void moveFish(vector<vector<pair<int, int> > >& fishByCoord, vector<tuple<int, int, int> >& fishByNum, int sharkR, int sharkC) {
    for (int i = 1; i <= N * N; ++i) {
        auto [r, c, dir] = fishByNum[i];
        if (dir == -1) {
            continue;
        }
        while ((r + dr[dir] == sharkR && c + dc[dir] == sharkC) || (r + dr[dir] < 0 || r + dr[dir] >= N || c + dc[dir] < 0 || c + dc[dir] >= N)) {
            dir = dir % 8 + 1;
        }

        int nr = r + dr[dir];
        int nc = c + dc[dir];
        auto [nNum, ndir] = fishByCoord[nr][nc];

        fishByCoord[nr][nc] = {i, dir};
        fishByNum[nNum] = {r, c, ndir};
        fishByNum[i] = {nr, nc, dir};
        fishByCoord[r][c] = {nNum, ndir};
    }
}

void f(vector<vector<pair<int, int> > > fishByCoord, vector<tuple<int, int, int> > fishByNum, int sharkR, int sharkC) {
    auto & [num, dir] = fishByCoord[sharkR][sharkC];

    int ndir = dir;
    fishByNum[num] = {0, 0, -1};
    dir = -1;

    moveFish(fishByCoord, fishByNum, sharkR, sharkC);

    bool canMove = false;

    for (int i = 1; i <= 3; ++i) {
        int nr = sharkR + dr[ndir] * i;
        int nc = sharkC + dc[ndir] * i;

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
            break;
        }

        if (fishByCoord[nr][nc].second == -1) {
            continue;
        }

        canMove = true;
        f(fishByCoord, fishByNum, nr, nc);
    }

    if (!canMove) {
        int tmp = 0;
        for (int i = 1; i <= N * N; ++i) {
            if (get<2>(fishByNum[i]) == -1) {
                tmp += i;
            }
        }
        answer = max(answer, tmp);
        return;
    }
}

int main() {
    // num dir
    vector<vector<pair<int, int> > > fishByCoord(N, vector<pair<int, int> > (N));
    // r, c, dir
    vector<tuple<int, int, int> > fishByNum(N * N + 1);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> fishByCoord[i][j].first >> fishByCoord[i][j].second;
            fishByNum[fishByCoord[i][j].first] = {i, j, fishByCoord[i][j].second};
        }
    }

    f(fishByCoord, fishByNum, 0, 0);
    cout << answer << '\n';
}