#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, K;
vector<vector<int> > A(100, vector<int> (100, 0));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> K;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }

    int time = 0;
    int widthMax = 3;
    int heightMax = 3;

    for (; time <= 100; time++) {
        if (A[R - 1][C - 1] == K) {
            break;
        }

        if (widthMax <= heightMax) {
            // row calc
            int nextWidthMax = 0;
            for (int i = 0; i < heightMax; i++) {
                vector<int> tmp(101, 0);
                // count num;
                for (int j = 0; j < widthMax; j++) {
                    if (A[i][j] == 0) {
                        continue;
                    } else {
                        tmp[A[i][j]]++;
                    }
                }
                // count, num
                vector<pair<int, int> > tmp2;

                for (int num = 1; num < 101; num++) {
                    if (tmp[num] != 0) {
                        tmp2.push_back({tmp[num], num});
                    }
                }
                nextWidthMax = max(nextWidthMax, int(2 * tmp2.size()));
                sort(tmp2.begin(), tmp2.end());

                int k = 0;


                for (; k < tmp2.size() && k < 50; k++) {
                    A[i][2 * k] = tmp2[k].second;
                    A[i][2 * k + 1] = tmp2[k].first; 
                }
                for (; k < 50; k++) {
                    A[i][2 * k] = 0;
                    A[i][2 * k + 1] = 0; 
                }
            }

            widthMax = nextWidthMax;
        } else {
            // col calc
            int nextHeightMax = 0;
            for (int j = 0; j < widthMax; j++) {
                vector<int> tmp(101, 0);
                // count num;
                for (int i = 0; i < heightMax; i++) {
                    if (A[i][j] == 0) {
                        continue;
                    } else {
                        tmp[A[i][j]]++;
                    }
                }
                // count, num
                vector<pair<int, int> > tmp2;

                for (int num = 1; num < 101; num++) {
                    if (tmp[num] != 0) {
                        tmp2.push_back({tmp[num], num});
                    }
                }
                nextHeightMax = max(nextHeightMax, int(2 * tmp2.size()));
                sort(tmp2.begin(), tmp2.end());

                int k = 0;


                for (; k < tmp2.size() && k < 50; k++) {
                    A[2 * k][j] = tmp2[k].second;
                    A[2 * k + 1][j] = tmp2[k].first; 
                }
                for (; k < 50; k++) {
                    A[2 * k][j] = 0;
                    A[2 * k + 1][j] = 0; 
                }
            }

            heightMax = nextHeightMax;
        }
    }


    if (time == 101) {
        cout << "-1\n";
    } else {
        cout << time << "\n";
    }

}