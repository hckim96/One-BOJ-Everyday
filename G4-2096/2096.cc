#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 100000

int N;
int dpMax[2][3];
int dpMin[2][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int j = 0; j < 3; j++) {
        cin >> dpMax[0][j];
        dpMin[0][j] = dpMax[0][j];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> dpMax[1][j];
            dpMin[1][j] = dpMax[1][j];
        }

        dpMax[1][0] += max(dpMax[0][0], dpMax[0][1]);
        dpMax[1][1] += max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2]));
        dpMax[1][2] += max(dpMax[0][1], dpMax[0][2]);

        dpMin[1][0] += min(dpMin[0][0], dpMin[0][1]);
        dpMin[1][1] += min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));
        dpMin[1][2] += min(dpMin[0][1], dpMin[0][2]);

        for (int j = 0; j < 3; j++) {
            dpMax[0][j] = dpMax[1][j];
            dpMin[0][j] = dpMin[1][j];
        }
    }

    int retMin, retMax;

    retMax = max(dpMax[0][0], max(dpMax[0][1], dpMax[0][2]));
    retMin = min(dpMin[0][0], min(dpMin[0][1], dpMin[0][2]));

    cout << retMax << " " << retMin << "\n";
}