#include <iostream>
#include <vector>

using namespace std;

void f(vector<string>& arr, int i, int j, int size) {
    
    if (size == 1) {
        cout << arr[i][j];
        return;
    }

    bool flag = false;
    for (int r = i; r < i + size; ++r) {
        for (int c = j; c < j + size; ++c) {
            if (arr[i][j] != arr[r][c]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    if (flag) {
        size >>= 1;

        cout << '(';
        for (int ii = 0; ii < 2; ++ii) {
            for (int jj = 0; jj < 2; ++jj) {
                f(arr, i + size * ii, j + size * jj, size);
            }
        }
        cout << ')';
    } else {
        cout << arr[i][j];
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    f(arr, 0, 0, N);
}