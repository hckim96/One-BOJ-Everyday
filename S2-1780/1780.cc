#include <iostream>
#include <vector>

using namespace std;

void f(vector<vector<int> >& arr, vector<int>& cnt, int i, int j, int len) {
    if (len == 1) {
        ++cnt[arr[i][j] + 1];
        return;
    }
    
    bool flag = false;

    for (int ii = i; ii < i + len; ++ii) {
        if (flag) {
            break;
        }
        for (int jj = j; jj < j + len; ++jj) {
            if (arr[i][j] != arr[ii][jj]) {
                flag = true;
                break;            
            }
        }
    }

    if (flag) {
        int nlen = len / 3;
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                f(arr, cnt, i + nlen * k, j + nlen * l, nlen);
            }
        }
    } else {
        ++cnt[arr[i][j] + 1];
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

    // -1, 0, 1
    vector<int> cnt(3, 0);

    f(arr, cnt, 0, 0, N);

    for (auto e: cnt) {
        cout << e << '\n';
    }
}