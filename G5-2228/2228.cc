#include <iostream>

using namespace std;

#define N_MAX 100

int N, M;
int sum[N_MAX + 1] = {0};
int dp[N_MAX + 1][(N_MAX + 1) / 2 + (N_MAX + 1) % 2] = {0};

// n번째 까지 sectionCnt 개수 구간의 총합 중 최대
int maxSum(int n, int sectionCnt) {
    if (sectionCnt == 0) {
        return 0;
    }
    if (n <= 0) {
        return -987654321;
    }
    if (dp[n][sectionCnt] != 0) {
        return dp[n][sectionCnt];
    }

    int ret = -987654321;
    // 마지막 구간에 n번째 포함, n번째 안포함

    // n번째 안포함
    ret = max(ret, maxSum(n - 1, sectionCnt));
    
    // n번쨰 포함
    for (int i = 1; i <= n; i++) {
        ret = max(ret, maxSum(n - i - 1, sectionCnt - 1) + sum[n] - sum[n - i]); 
    }

    return dp[n][sectionCnt] = ret;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }

    cout << maxSum(N, M) << "\n";
}