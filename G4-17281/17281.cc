#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 50

int arr[N_MAX][9] = {0};

// 1 번 선수 제외 순서
int order[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int N;
int answer = 0;

int calculateScore() {
    int inning = 0;
    int hitterIndex = 0;
    int hitter = order[hitterIndex];
    int score = 0;
    while (inning < N) {
        int out = 0;
        int base[4] = {0};
        while (out < 3) {
            if (hitterIndex == 3) {
                hitter = 0;
            } else {
                if (hitterIndex < 3) {
                    hitter = order[hitterIndex];
                } else {
                    hitter = order[hitterIndex - 1];
                }
            }
            hitterIndex = (hitterIndex + 1) % 9;

            if (arr[inning][hitter] == 0) {
                out++;
                continue;
            }

            base[0] = 1;
            for (int i = 3; i >=0; i--) {
                if (base[i] == 0) {
                    continue;
                }

                if (i + arr[inning][hitter] >= 4) {
                    score += base[i];
                    base[i] = 0;
                } else {
                    base[i + arr[inning][hitter]] = base[i];
                    base[i] = 0;
                }
            }
        }
        inning++;
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
        }
    }

    do {
        answer = max(answer, calculateScore());
    } while (next_permutation(order, order + 8));

    cout << answer << "\n";
}