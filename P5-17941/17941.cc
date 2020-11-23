#include <iostream>
#include <algorithm>

using namespace std;

#define Q_MAX 50000
#define COORDINATE_MAX 500

int N, M, Q, X, Y, R, C, K, D;

// 1- index
int sheepSize[COORDINATE_MAX + 1][COORDINATE_MAX + 1];

// 1 - index
int segmentTree[4 * COORDINATE_MAX] = {0};


int initSeg(int* lineMax, int nodeNum, int nodeStart, int nodeEnd) {
    if (nodeStart == nodeEnd) {
        return segmentTree[nodeNum] = lineMax[nodeStart];
    }

    int mid = (nodeStart + nodeEnd) / 2;
    return segmentTree[nodeNum] = max(initSeg(lineMax, nodeNum * 2, nodeStart, mid), initSeg(lineMax, nodeNum * 2 + 1, mid + 1, nodeEnd));
}

int getMaxSeg(int nodeNum, int nodeStart, int nodeEnd, int segStart, int segEnd) {
    if (segEnd < nodeStart || nodeEnd < segStart) {
        return 0;
    }
    if (segStart <= nodeStart && nodeEnd <= segEnd) {
        return segmentTree[nodeNum];
    }
    int mid = (nodeStart + nodeEnd) / 2;
    return max(getMaxSeg(nodeNum * 2, nodeStart, mid, segStart, segEnd), getMaxSeg(nodeNum * 2 + 1, mid + 1, nodeEnd, segStart, segEnd));

}

int getAnswer(int X, int Y, int R, int C, int K, int D) {
    // 1 - index
    int lineMax[COORDINATE_MAX + 1] = {0};
    fill_n(segmentTree, 4 * COORDINATE_MAX, 0);

    int answer = 0;
    switch (D) {
        case 1:
            for (int i = X; i <= N; i++) {
                for (int j = Y; j < Y + C; j++) {
                    lineMax[i] = max(lineMax[i], sheepSize[i][j]);
                }
            }
            initSeg(lineMax, 1, X, N);
            for (int i = 0; i < K; i++) {
                // cout << getMaxSeg(1, X, N, X + i, X + R - 1 + i) << "\n";
                answer = answer ^ getMaxSeg(1, X, N, X + i, X + R - 1 + i);
            }
            break;
        case 2:
            for (int i = 1; i < X + R; i++) {
                for (int j = Y; j < Y + C; j++) {
                    lineMax[i] = max(lineMax[i], sheepSize[i][j]);
                }
            }
            initSeg(lineMax, 1, 1, X + R - 1);
            for (int i = 0; i < K; i++) {
                // cout << getMaxSeg(1, X, X + R - 1, X - i, X + R - 1 - i) << "\n";
                answer = answer ^ getMaxSeg(1, X, X + R - 1, X - i, X + R - 1 - i);
            }
            break;
        case 3:
            for (int i = X; i < X + R; i++) {
                for (int j = Y; j <= M; j++) {
                    lineMax[j] = max(lineMax[j], sheepSize[i][j]);
                }
            }
            initSeg(lineMax, 1, Y, M);
            for (int i = 0; i < K; i++) {
                // cout << getMaxSeg(1, Y, M, Y + i, Y + C - 1 + i) << "\n";
                answer = answer ^ getMaxSeg(1, Y, M, Y + i, Y + C - 1 + i);
            }
            break;
        case 4:
            for (int i = X; i < X + R; i++) {
                for (int j = 1; j < Y + C; j++) {
                    lineMax[j] = max(lineMax[j], sheepSize[i][j]);
                }
            }
            // cout << "\nlineMax\n";
            // for (int j = 1; j < Y + C; j++) {
            //     cout << lineMax[j] << " ";
            // }
            // cout << "\n";
            initSeg(lineMax, 1, 1, Y + C - 1);
            for (int i = 0; i < K; i++) {
                // cout << getMaxSeg(1, 1, Y + C - 1, Y - i, Y + C - 1 - i) << "\n";
                // cout << Y - i << ", " << Y + C - 1 - i << "\n";

                answer = answer ^ getMaxSeg(1, 1, Y + C - 1, Y - i, Y + C - 1 - i);
            }
            break;
    }


    return answer;


}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> sheepSize[i][j];
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> X >> Y >> R >> C >> K >> D;
        cout << getAnswer(X, Y, R, C, K, D) << "\n";

    }
}