#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

#define COORDINATE_MAX 500

int N, M, Q, X, Y, R, C, K, D;

int sheepSize[COORDINATE_MAX][COORDINATE_MAX];
int segRow[COORDINATE_MAX][2 * COORDINATE_MAX];
int segCol[COORDINATE_MAX][2 * COORDINATE_MAX];
int maxOfLine[COORDINATE_MAX] = {0};
void initSegRow(int r) {
    for (int i = M - 1; i > 0; i--) {
        segRow[r][i] = max(segRow[r][i << 1], segRow[r][i << 1 | 1]);
    }
}

void initSegCol(int c) {
    for (int i = N - 1; i > 0; i--) {
        segCol[c][i] = max(segCol[c][i << 1], segCol[c][i << 1 | 1]);
    }
}

int queryRow(int r, int targetStart, int targetEnd) {
    int ret = 0;
    for (targetStart += M, targetEnd += M + 1; targetStart < targetEnd; targetStart >>= 1, targetEnd >>= 1) {
        if (targetStart & 1) {
            ret = max(ret, segRow[r][targetStart++]);
        }
        if (targetEnd & 1) {
            ret = max(ret, segRow[r][--targetEnd]);
        }
    }
    return ret;
}

int queryCol(int c, int targetStart, int targetEnd) {
    int ret = 0;
    for (targetStart += N, targetEnd += N + 1; targetStart < targetEnd; targetStart >>= 1, targetEnd >>= 1) {
        if (targetStart & 1) {
            ret = max(ret, segCol[c][targetStart++]);
        }
        if (targetEnd & 1) {
            ret = max(ret, segCol[c][--targetEnd]);
        }
    }
    return ret;
}

void makeMaxOfLine(int targetStart, int targetEnd) {
    switch (D) {
        case 1:
            for (int i = 0; X + i < N; i++) {
                maxOfLine[i] = queryRow(X + i, targetStart, targetEnd);
            }
            break;
        case 2:
            for (int i = 0; X + R - 1 - i >= 0; i++) {
                maxOfLine[i] = queryRow(X + R - 1 - i, targetStart, targetEnd);
            }
            break;
        case 3:
            for (int i = 0; Y + i < M; i++) {
                maxOfLine[i] = queryCol(Y + i, targetStart, targetEnd);
            }
            break;
        case 4:
            for (int i = 0; Y + C - 1 - i >= 0; i++) {
                maxOfLine[i] = queryCol(Y + C - 1 - i, targetStart, targetEnd);
            }
            break;
        default:
            break;
    }
}

void slidingWindow(int windowSize) {
    // index, value
    deque <pair<int, int> > dq;

    int ret = 0;

    for (int i = 0; i < K - 1 + windowSize; i++) {

        // 윈도우 범위 밖
        while (!dq.empty() && i - dq.front().first >= windowSize) {
            dq.pop_front();
        }

        // 넣을 값보다 작은 값 
        while (!dq.empty() && dq.back().second < maxOfLine[i]) {
            dq.pop_back();
        }
        while (!dq.empty() && dq.front().second < maxOfLine[i]) {
            dq.pop_front();
        }

        dq.push_back({i, maxOfLine[i]});

        if (i >= windowSize - 1) {
            ret = ret ^ dq.front().second;
        }
    }
    cout << ret << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> sheepSize[i][j];
            segRow[i][M + j] = sheepSize[i][j];
            segCol[j][N + i] = sheepSize[i][j];
        }
    }

    cin >> Q;

    for (int i = 0; i < N; i++) {
        initSegRow(i);
    }
    for (int i = 0; i < M; i++) {
        initSegCol(i);
    }

    for (int i = 0; i < Q; i++) {
        cin >> X >> Y >> R >> C >> K >> D;
        X--;
        Y--;
        switch (D) {
            case 1:
                makeMaxOfLine(Y, Y + C - 1);
                slidingWindow(R);
                break;
            case 2:
                makeMaxOfLine(Y, Y + C - 1);
                slidingWindow(R);
                break;
            case 3:
                makeMaxOfLine(X, X + R - 1);
                slidingWindow(C);
                break;
            case 4:
                makeMaxOfLine(X, X + R - 1);
                slidingWindow(C);
                break;
        }
    }
}