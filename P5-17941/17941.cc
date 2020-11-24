#include <iostream>
#include <algorithm>

using namespace std;

#define Q_MAX 50000
#define COORDINATE_MAX 500

int N, M, Q, X, Y, R, C, K, D;

// 0 - index
int sheepSize[COORDINATE_MAX][COORDINATE_MAX];
int seg2d[2 * COORDINATE_MAX][2 * COORDINATE_MAX];

// Bottom-up

void initSeg2d() {
    // left bottom part
    for (int i = N; i < 2 * N; i++) {
        for (int j = M - 1; j > 0; j--) {
            seg2d[i][j] = max(seg2d[i][j << 1], seg2d[i][j << 1 | 1]);
        }
    }

    // upper part
    for (int i = N - 1; i > 0; i--) {
        for (int j = 1; j < 2 * M; j++) {
            seg2d[i][j] = max(seg2d[i << 1][j], seg2d[i << 1 | 1][j]);
        }
    }
}

int query1d(int r, int c1, int c2) {
    int ret = 0;
    int left = M + c1;
    int right = M + c2 + 1;

    for (; left < right; left >>= 1, right >>= 1) {
        if (left & 1) {
            ret = max(ret, seg2d[r][left++]);
        }
        if (right & 1) {
            ret = max(ret, seg2d[r][--right]);
        }
    }
    return ret;
}

int query2d(int r1, int r2, int c1, int c2) {

    int ret = 0;
    int top = N + r1;
    int bottom = N + r2 + 1;

    for (; top < bottom; top >>= 1, bottom >>= 1) {
        if (top & 1) {
            ret = max(ret, query1d(top++, c1, c2));
        }
        if (bottom & 1) {
            ret = max(ret, query1d(--bottom, c1, c2));
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sheepSize[i][j];
            seg2d[N + i][M + j] = sheepSize[i][j];
        }
    }

    cin >> Q;

    initSeg2d();

    for (int i = 0; i < Q; i++) {
        cin >> X >> Y >> R >> C >> K >> D;
        X--;
        Y--;
        int ret = 0;

        switch (D) {
            case 1:
                for (int j = 0; j < K; j++) {
                    ret = ret ^ query2d(X + j, X + R - 1 + j, Y, Y + C - 1);
                    // cout << "\n max: " << query2d(X + j, X + R - 1 + j, Y, Y + C - 1) << "\n";
                }
                break;
            case 2:
                for (int j = 0; j < K; j++) {
                    ret = ret ^ query2d(X - j, X + R - 1 - j, Y, Y + C - 1);
                    // cout << "\n max: " << query2d(X - j, X + R - 1 - j, Y, Y + C - 1) << "\n";
                }
                break;
            case 3:
                for (int j = 0; j < K; j++) {
                    ret = ret ^ query2d(X, X + R - 1, Y + j, Y + C - 1 + j);
                    // cout << "\n max: " << query2d(X, X + R - 1, Y + j, Y + C - 1 + j) << "\n";
                }
                break;
            case 4:
                for (int j = 0; j < K; j++) {
                    ret = ret ^ query2d(X, X + R - 1, Y - j, Y + C - 1 - j);
                    // cout << "\n max: " << query2d(X, X + R - 1, Y - j, Y + C - 1 - j) << "\n";
                }
                break;
        }
        cout << ret << "\n";
    }
}