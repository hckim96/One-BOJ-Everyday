#include <iostream>
#include <queue>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int up[4] = {3, 0, 2, 1};
int down[4] = {2, 0, 3, 1};

int A[50][50];
int R, C, T;
int cleanerUp = -1, cleanerDown;

void blowUp() {
    // up
    int nextR = cleanerUp - 1, nextC = 0; 

    for (int i = 0; i < 4; i++) {
        while (true) {
            int destR = nextR;
            int destC = nextC; 
            nextR += dr[up[i]];
            nextC += dc[up[i]];

            if (nextR < 0 || nextR > cleanerUp || nextC < 0 || nextC >= C) {
                nextR -= dr[up[i]];
                nextC -= dc[up[i]];
                break;
            }


            if (nextR == cleanerUp && nextC == 0) {
                A[destR][destC] = 0;
                return;
            }

            A[destR][destC] = A[nextR][nextC];
        }
    }

}
void blowDown() {
    // down
    int nextR = cleanerDown + 1, nextC = 0; 

    for (int i = 0; i < 4; i++) {
        while (true) {
            int destR = nextR;
            int destC = nextC; 
            nextR += dr[down[i]];
            nextC += dc[down[i]];

            if (nextR < cleanerDown || nextR >= R || nextC < 0 || nextC >= C) {
                nextR -= dr[down[i]];
                nextC -= dc[down[i]];
                break;
            }

            if (nextR == cleanerDown && nextC == 0) {
                A[destR][destC] = 0;
                return;
            }

            A[destR][destC] = A[nextR][nextC];
        }
    }
}

struct Dust {
    int r;
    int c;
    int concentration;
};
queue<Dust> q;
void spreadDust() {
    queue<Dust> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] > 0) {
                q.push(Dust{i, j, A[i][j]});
            }
        }
    }

    while (!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int concentration = q.front().concentration;
        q.pop();

        int dirCnt = 0;
        int dConcentration = concentration / 5;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) {
                continue;
            }
            
            if (A[nr][nc] == -1) {
                continue;
            }
            dirCnt++;
            A[nr][nc] += dConcentration;
        }

        A[r][c] -= dirCnt * dConcentration;
    }
}

void getTotalConcentrationAfter(int sec) {
    int k = 0;
    while (sec-- > 0) {
        spreadDust();
        blowUp();
        blowDown();
        k++;

    }

    int answer = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (A[i][j] > 0) {
                answer += A[i][j];
            }
        }
    }
    cout << answer << "\n";
    
}
int main() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> A[i][j];
            if (A[i][j] == -1) {
                if (cleanerUp == -1) {
                    cleanerUp = i;
                } else {
                    cleanerDown = i;
                }
            }
        }
    }

    getTotalConcentrationAfter(T);

}