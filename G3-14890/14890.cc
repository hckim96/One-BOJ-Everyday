#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    vector<vector<int> > arr(N, vector<int> (N));

    for (auto & e: arr) {
        for (auto & ee: e) {
            cin >> ee;
        }
    }

    int answer = 0;

    // row
    for (int i = 0; i < N; ++i) {

        bool canpass = true;
        int flatCnt = 1;
        vector<bool> slope(N, 0);
        for (int j = 0; j < N - 1; ++j) {
            if (arr[i][j] < arr[i][j + 1]) {
                if (arr[i][j] + 1 < arr[i][j + 1]) {
                    canpass = false;
                    break;
                }
                
                if (flatCnt >= L) {
                    flatCnt = 1;
                    slope[j] = true;
                } else {
                    canpass = false;
                    break;
                }
            } else if (arr[i][j] == arr[i][j + 1]) {
                ++flatCnt;
            } else {
                flatCnt = 1;
            }
        }

        if (!canpass) {
            continue;
        }

        flatCnt = 1;
        for (int j = N - 1; j > 0; --j) {
            if (arr[i][j] < arr[i][j - 1]) {
                if (arr[i][j] + 1 < arr[i][j - 1]) {
                    canpass = false;
                    break;
                }

                if (flatCnt >= L) {
                    if (!canpass) {
                        break;
                    }
                    flatCnt = 1;
                    continue;
                } else {
                    canpass = false;
                    break;
                }
            } else if (arr[i][j] == arr[i][j - 1]) {
                ++flatCnt;
            } else {
                if (!slope[j - 1]) {
                    canpass = false;
                    break;
                }

                j -= L - 1;
                flatCnt = 0;
            }
        }

        if (canpass) {
            ++answer;
        }
    }

    // col
    for (int i = 0; i < N; ++i) {

        bool canpass = true;
        int flatCnt = 1;
        vector<bool> slope(N, 0);
        for (int j = 0; j < N - 1; ++j) {
            if (arr[j][i] < arr[j + 1][i]) {
                if (arr[j][i] + 1 < arr[j + 1][i]) {
                    canpass = false;
                    break;
                }

                if (flatCnt >= L) {
                    flatCnt = 1;
                    slope[j] = true;
                } else {
                    canpass = false;
                    break;
                }
            } else if (arr[j][i] == arr[j + 1][i]) {
                ++flatCnt;
            } else {
                flatCnt = 1;
            }
        }

        if (!canpass) {
            continue;
        }

        flatCnt = 1;
        for (int j = N - 1; j > 0; --j) {
            if (arr[j][i] < arr[j - 1][i]) {
                if (arr[j][i] + 1 < arr[j - 1][i]) {
                    canpass = false;
                    break;
                }

                if (flatCnt >= L) {
                    if (!canpass) {
                        break;
                    }
                    flatCnt = 1;
                    continue;
                } else {
                    canpass = false;
                    break;
                }
            } else if (arr[j][i] == arr[j - 1][i]) {
                ++flatCnt;
            } else {
                if (!slope[j - 1]) {
                    canpass = false;
                    break;
                }

                j -= L - 1;
                flatCnt = 0;
            }
        }

        if (canpass) {
            ++answer;
        }
    }

    cout << answer << '\n';
}