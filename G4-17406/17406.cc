#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

#define N_MAX 50
#define K_MAX 6
#define INF 987654321

int N, M, K;
vector<vector<int> > arr(N_MAX, vector<int> (N_MAX, 0));
tuple<int, int, int> operation[K_MAX];
int answer = INF;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void rotateOperation(vector<vector<int> >& arrCopy , int r, int c, int s) {
    int layer = s;

    for (; layer > 0; layer--) {
        int last = arrCopy[r - layer][c - layer];

        int dir = 0;

        int rr, cc;

        rr = r - layer + 1;
        cc = c - layer;

        while (!(rr == r - layer && cc == c - layer)) {
            int prr = rr - dr[dir];
            int pcc = cc - dc[dir];

            arrCopy[prr][pcc] = arrCopy[rr][cc];

            int nrr = rr + dr[dir];
            int ncc = cc + dc[dir];
            if (nrr < r - layer || nrr > r + layer || ncc < c - layer || ncc > c + layer) {
                dir = (dir + 1) % 4;
            }

            rr = rr + dr[dir];
            cc = cc + dc[dir];
        }
        arrCopy[rr - dr[dir]][cc - dc[dir]] = last;
    }
}

void calculateValueOfArr(vector<vector<int> >& arrCopy) {
    int rowMin, rowSum;

    rowMin = INF;

    for (int i = 0; i < N; i++) {
        rowSum = 0;
        for (int j = 0; j < M; j++) {
            rowSum += arrCopy[i][j];
        }
        rowMin = min(rowMin, rowSum);
    }
    answer = min(answer, rowMin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        operation[i] = {r - 1, c - 1, s};
    }

    sort(&operation[0], &operation[0] + K);

    do {
        vector<vector<int> > arrCopy(arr);
        
        for (int i = 0; i < K; i++) {
            auto [a, b, c] = operation[i];
            rotateOperation(arrCopy, a, b, c);
        }
        calculateValueOfArr(arrCopy);

    } while (next_permutation(&operation[0], &operation[0] + K));

    cout << answer << "\n";
}