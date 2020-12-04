#include <iostream>

using namespace std;

pair<int, int> todo[9 * 9];
int todoCnt = 0;

int map[9][9] = {0};
bool foundAnswer = false;

void dfs(int todoIdx) {

    if (foundAnswer) {
        return;
    }

    int r, c;
    r = todo[todoIdx].first;
    c = todo[todoIdx].second;

    bool canNotInsert[10] = {0};
    int rectR = (r / 3) * 3;
    int rectC = (c/ 3) * 3;

    // row, col
    for (int i = 0; i < 9; i++) {
        canNotInsert[map[r][i]] = true;
        canNotInsert[map[i][c]] = true;
    }

    // rectangle
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            canNotInsert[map[rectR + i][rectC + j]] = true;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (canNotInsert[i]) {
            continue;
        }

        map[r][c] = i;
        if (todoIdx == todoCnt - 1) {
            foundAnswer = true;

            for (int k = 0; k < 9; k++) {
                for (int l = 0; l < 9; l++) {
                    cout << map[k][l] << " ";
                }
                cout << "\n";
            }
            return;
        }

        dfs(todoIdx + 1);
        map[r][c] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];

            if (map[i][j] == 0) {
                todo[todoCnt] = {i, j};
                todoCnt++;
            }
        }
    }

    dfs(0);

    return 0;
}