#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
void f(vector<vector<int> >& arr, vector<bool>& rb, int lbIdx, int cnt) {
    int N = arr.size();

    if (lbIdx >= 2 * N - 1) {
        answer = max(answer, cnt);
        return;
    }

    int rs, re;

    if (lbIdx >= N) {
        rs = lbIdx - N + 1;
        re = N - 1;
    } else {
        rs = 0;
        re = lbIdx;
    }

    bool flag = false;
    for (int r = rs; r <= re; ++r) {
        int c = lbIdx - r;
        int rbIdx = c - r + N - 1;
        if (arr[r][c] && !rb[rbIdx]) {
            flag = true;
            rb[rbIdx] = true;
            f(arr, rb, lbIdx + 2, cnt + 1);
            rb[rbIdx] = false;
        }
    }

    if (!flag) {
        f(arr, rb, lbIdx + 2, cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int> > arr(N, vector<int> (N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<bool> rb(2 * N - 1, false);
    
    f(arr, rb, 0, 0);
    int tmp = answer;
    answer = 0;
    f(arr, rb, 1, 0);

    cout << tmp + answer << '\n';
}
