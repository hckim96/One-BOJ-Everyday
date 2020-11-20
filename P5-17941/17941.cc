#include <iostream>
#include <algorithm>

using namespace std;

#define Q_MAX 50000
#define COORDINATE_MAX 500

int N, M, Q, X, Y, R, C, K, D;

// 0-index

int sheepSize[COORDINATE_MAX][COORDINATE_MAX];
int colMax[COORDINATE_MAX] = {0};
int rowMax[COORDINATE_MAX] = {0};

int getMax() {

    switch (D) {
        case 1:
            
    }
    int maxSize = 0;
    for (int i = X - 1; i < X - 1 + R; i++) {
        for (int j = Y - 1; j < Y - 1 + C; j++) {
            if (i < 0 || i >= N || j < 0 || j >= M) {
                continue;
            }
            maxSize = maxSize < sheepSize[i][j] ? sheepSize[i][j] : maxSize;
        }
    }

    return maxSize;
}


int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
// move cctv
void move() {
    X = X + dr[D - 1];
    Y = Y + dc[D - 1];
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sheepSize[i][j];
            rowMax[i] = max(rowMax[i], sheepSize[i][j]);
            colMax[j] = max(colMax[j], sheepSize[i][j]);
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> X >> Y >> R >> C >> K >> D;
        int ret = 0;
        for (int j = 0; j < K; j++) {
            ret = ret ^ getMax();
            move();
        }

        cout << ret << "\n";
    }
}