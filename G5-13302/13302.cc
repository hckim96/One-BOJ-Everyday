#include <iostream>

using namespace std;

#define N_MAX 100

// 1 3 5 coupon
int PRICE[4] = {10000, 25000, 37000, 0}; 

bool canUse[N_MAX + 1];

int answer = 987654321;

int N, M;
int dp[N_MAX + 1][N_MAX + 1][N_MAX + 1] = {0};

int dfs(int day, int left, int coupon) {

    if (day > N) {
        return 0;
    }

    if (dp[day][left][coupon] != 0) {
        return dp[day][left][coupon];
    }

    int ret = 987654321;

    if (left != 0) {
        ret = min(ret, dfs(day + 1, left - 1, coupon));
    } else {
        if (canUse[day]) {
            // should buy
            for (int i = 0; i < 4; i++) {
                if (i == 3) {
                    if (coupon >= 3) {
                        ret = min(ret, dfs(day + 1, 0, coupon - 3));
                    }
                } else {
                    ret = min(ret, dfs(day + 1, 2 * i, coupon + i) + PRICE[i]);
                }
            }
        } else {
            // pass
            ret = min(ret, dfs(day + 1, 0, coupon));
        }
    }
    return dp[day][left][coupon] = ret;
}


int main() {
    cin >> N >> M;

    fill_n(canUse, N_MAX + 1, true);

    for (int i = 0; i < M; i++) {
        int cantUse;
        cin >> cantUse;
        canUse[cantUse] = false;
    }

    cout << dfs(1, 0, 0) << "\n";
}