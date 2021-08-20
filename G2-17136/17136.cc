#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int answer = INF;

// 종이 있는지, 놓을 수 있는지 체크
bool canPut(vector<vector<int> >& arr, vector<int>& paper, int r, int c, int size) {
    if (!paper[size]) {
        return false;
    }

    if (r + size - 1 >= 10 || c + size - 1 >= 10) {
        return false;
    }

    bool flag = true;

    for (int i = r; i < r + size; ++i) {
        for (int j = c; j < c + size; ++j) {
            if (!arr[i][j]) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }
    return flag;
}

void cover(vector<vector<int> >& arr, int r, int c, int size) {
    for (int i = r; i < r + size; ++i) {
        for (int j = c; j < c + size; ++j) {
            arr[i][j] = 0;
        }
    }
}

void unCover(vector<vector<int> >& arr, int r, int c, int size) {
    for (int i = r; i < r + size; ++i) {
        for (int j = c; j < c + size; ++j) {
            arr[i][j] = 1;
        }
    }
}

void f(vector<vector<int> >& arr, vector<int>& paper, int r, int c, int leftCnt) {
    if (10 * r + c >= 100 || leftCnt == 0) {
        if (leftCnt == 0) {
            int tmp = 25;
            for (int i = 1; i <= 5; ++i) {
                tmp -= paper[i];
            }
            answer = min(answer, tmp);
        }
        return;
    }

    if (!arr[r][c]) {
        int nidx = 10 * r + c + 1;
        f(arr, paper, nidx / 10, nidx % 10, leftCnt);
        return;
    }

    for (int i = 1; i <= 5; ++i) {
        if (canPut(arr, paper, r, c, i)) {
            cover(arr, r, c, i);
            --paper[i];

            int nidx = 10 * r + c + i;
            f(arr, paper, nidx / 10, nidx % 10, leftCnt - i * i);

            ++paper[i];
            unCover(arr, r, c, i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int> > arr(10, vector<int> (10));

    int leftCnt = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                ++leftCnt;
            }
        }
    }

    vector<int> paper(6, 5);

    f(arr, paper, 0, 0, leftCnt);

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }
}