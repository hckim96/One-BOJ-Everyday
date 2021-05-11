#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void press(vector<int>& arr, int r, int c) {
    arr[r] ^= (1 << c);
    for (int dir = 0; dir < 4; ++dir) {
        int nr = r + dr[dir];
        int nc = c + dc[dir];

        if (nr < 0 || nr >= arr.size() || nc < 0 || nc >= arr.size()) {
            continue;
        }
        arr[nr] ^= (1 << nc);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 10;

    vector<int> arr(N, 0);

    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            if (s[j] == 'O') {
                arr[i] |= (1 << j);
            }
        }
    }

    int answer = INF;

    for (int c = 0; c < (1 << N); ++c) {
        vector<int> arrTmp(arr);
        int pressCnt = 0;

        for (int j = 0; j < N; ++j) {
            if (c < (1 << j)) {
                break;
            }
            
            if (c & (1 << j)) {
                press(arrTmp, 0, j);
                ++pressCnt;
            }
        }

        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (arrTmp[i - 1] < (1 << j)) {
                    break;
                }

                if (arrTmp[i - 1] & (1 << j)) {
                    press(arrTmp, i, j);
                    ++pressCnt;
                }
            }
        }

        bool flag = true;

        for (int i = 0; i < N; ++i) {
            if (arrTmp[i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            answer = min(answer, pressCnt);
        }
    }

    if (answer == INF) {
        cout << "-1\n";
    } else {
        cout << answer << '\n';
    }
}
