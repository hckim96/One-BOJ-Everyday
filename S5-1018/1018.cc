#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 50

int N, M;

// 0 white, 1 black
int map[N_MAX][N_MAX] = {0};
int answer = 987654321;

void check(int r, int c) {
    // check 2 cases : white first, black first

    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                if (map[r + i][c + j] == 0) {
                    cnt++;
                }
            } else {
                if (map[r + i][c + j] == 1) {
                    cnt++;
                }
            }
        }
    }
    answer = min(answer, cnt);

    cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                if (map[r + i][c + j] == 1) {
                    cnt++;
                }
            } else {
                if (map[r + i][c + j] == 0) {
                    cnt++;
                }
            }
        }
    }
    answer = min(answer, cnt);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            if (tmp[j] == 'B') {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N - 7; i++) {
        for (int j = 0; j < M - 7; j++) {
            check(i, j);
        }
    }

    cout << answer << "\n";
}