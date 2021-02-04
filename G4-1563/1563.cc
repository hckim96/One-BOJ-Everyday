#include <iostream>

using namespace std;

#define N_MAX 1000

int N;

// 날, 지, 연 결
int dp[N_MAX][2][3] = {0};

int f(int idx, int late, int absent) {
    if (late == 2 || absent == 3) {
        return 0;
    }

    if (idx == N) {
        return 1;
    }

    if (dp[idx][late][absent] != -1) {
        return dp[idx][late][absent];
    }

    return dp[idx][late][absent] = (f(idx + 1, late, 0) + f(idx + 1, late + 1, 0) + f(idx + 1, late, absent + 1)) % 1000000;
}

int main() {
    cin >> N;

    fill_n(&dp[0][0][0], N_MAX * 2 * 3, -1);
    
    cout << f(0, 0, 0) << '\n';
}