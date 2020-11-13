#include <iostream>

using namespace std;

#define N_MAX 50

int distanceArr[N_MAX + 1][N_MAX + 1];
int N;
int minDistance = 987654321;
int scores[N_MAX + 1];

int main() {
    fill(&distanceArr[0][0], &distanceArr[0][0] + (N_MAX + 1) * (N_MAX + 1), 987654321);
    fill_n(scores, N_MAX + 1, 0);
    cin >> N;

    while (1) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 == -1 && tmp2 == -1) {
            break;
        }

        distanceArr[tmp1][tmp2] = 1;
        distanceArr[tmp2][tmp1] = 1;
    }
    for (int i = 1; i <= N; i++) {
        distanceArr[i][i] = 0;
    }

    for (int intermediate = 1; intermediate <= N; intermediate++) {
        for (int from = 1; from <= N; from++) {
            for(int to = 1; to <= N; to++) {
                if (distanceArr[from][to] > distanceArr[from][intermediate] + distanceArr[intermediate][to]) {
                    distanceArr[from][to] = distanceArr[from][intermediate] + distanceArr[intermediate][to];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scores[i] = max(scores[i], distanceArr[i][j]);
        }
        minDistance = min(minDistance, scores[i]);
    }

    int minCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (scores[i] == minDistance) {
            minCnt++;
        }
    }

    cout << minDistance << " " << minCnt << "\n";

    for (int i = 1; i <= N; i++) {
        if (scores[i] == minDistance) {
            cout << i << " ";
        }
    }
    cout << "\n";

}