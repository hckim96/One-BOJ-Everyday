#include <iostream>
#include <algorithm>

using namespace std;

#define N_MAX 100000
#define M_MAX 10
int N, M;
int satisfaction[M_MAX + 1][N_MAX + 1] = {0};

// dp m,n : n 날에 m 먹었을 때 만족감 총합의 최대 
int dp[M_MAX][N_MAX] = {0};
int main() {
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> satisfaction[i][j];
        }
    }

    int answer = 0;
    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= M; i++) {
            for (int k = 1; k <= M; k++) {
                if (j == 1 || k != i) {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + satisfaction[i][j]);
                } else {
                    dp[i][j] = max(dp[i][j], dp[k][j - 1] + satisfaction[i][j] / 2);
                }
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        answer = max(answer, dp[i][N]);
    }

    cout << answer << "\n";
}