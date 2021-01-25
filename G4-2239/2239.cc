#include <iostream>

using namespace std;

int arr[9][9] = {0};
int row[9][10] = {0};
int col[9][10] = {0};
int sqr[9][10] = {0};
bool gotAnswer = false;

void dfs(int idx) {
    if (gotAnswer) {
        return;
    }
    int r = idx / 9;
    int c = idx % 9;

    int nidx = idx + 1;
    while (arr[nidx / 9][nidx % 9] != 0 && nidx < 81) {
        nidx++;
    }

    for (int i = 1; i <= 9; i++) {
        if (gotAnswer) {
            return;
        }

        bool canInsert = true;
        if (row[r][i] || col[c][i] || sqr[(r / 3) * 3 + c / 3][i]) {
            continue;
        }

        row[r][i] = 1;
        col[c][i] = 1;
        sqr[(r / 3) * 3 + c / 3][i] = 1;
        arr[r][c] = i;

        if (nidx == 81) {
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    cout << arr[j][k];
                }
                cout << "\n";
            }
            gotAnswer = true;
            return; 
        }

        dfs(nidx);

        arr[r][c] = 0;
        row[r][i] = 0;
        col[c][i] = 0;
        sqr[(r / 3) * 3 + c / 3][i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;

    for (int i = 0; i < 9; i++) {
        cin >> s;
        for (int j = 0; j < 9; j++) {
            int num = s[j] - '0';
            arr[i][j] = num;
            row[i][num] = 1;
            col[j][num] = 1;
            sqr[(i / 3) * 3 + j / 3][num] = 1;
        }
    }

    int idx = 0;
    while (arr[idx / 9][idx % 9] != 0 && idx < 81) {
        idx++;
    }

    if (idx == 81) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                cout << arr[j][k];
            }
            cout << "\n";
        }
        return 0;
    }

    dfs(idx);
}