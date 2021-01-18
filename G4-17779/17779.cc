#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 20
#define INF 987654321

int N;
int arr[N_MAX + 1][N_MAX + 1] = {0};
int answer = INF;

void calc(int r, int c, int d1, int d2) {
    int population[5] = {0};
    int populationMax, populationMin;
    populationMax = -1;
    populationMin = INF;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i + j <= r + c && i < r + d1 && j <= c) {
                population[0] += arr[i][j];
            } else if (j - i >= c - r && i <= r + d2 && c < j) {
                population[1] += arr[i][j];
            } else if (j - i <= c - r - 2 * d1 && r + d1 <= i && j < c - d1 + d2) {
                population[2] += arr[i][j];
            } else if (i + j >= r + c + 2 * d2 && r + d2 < i && c - d1 + d2 <= j) {
                population[3] += arr[i][j];
            } else {
                population[4] += arr[i][j];
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        populationMax = max(populationMax, population[i]);
        populationMin = min(populationMin, population[i]);
    }

    answer = min(answer, populationMax - populationMin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            for (int d1 = 1; d1 <= c - 1; d1++) {
                for (int d2 = 1; d2 <= N - c; d2++) {
                    if (d1 + d2 > N - r) {
                        continue;
                    }
                    calc(r, c, d1, d2);
                }
            }
        }
    }

    cout << answer << "\n";
}