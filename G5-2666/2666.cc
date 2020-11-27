#include <iostream>
#include <algorithm>

using namespace std;

#define USE_MAX 20
#define N_MAX 20
int N;
int useCnt;

// 1 - index
int use[USE_MAX + 1];


int dp[USE_MAX + 1][N_MAX + 1][N_MAX + 1] = {0};

// openedFirst, opendSecond 가 열려있을 때 useIdx 부터 끝까지 여는 최소 횟수
int minMoveCnt(int useIdx, int openedFirst, int openedSecond) {
    // cout << "minMoveCnt(" << useIdx << ", " << openedFirst << ", " << openedSecond << ")\n";
    if (useIdx > useCnt) {
        return 0;
    }

    int ret = 0;
    if (dp[useIdx][openedFirst][openedSecond] != 0) {
        return dp[useIdx][openedFirst][openedSecond];
    }

    // 이전에 구한 적 없음
    ret = min(abs(use[useIdx] - openedFirst) + minMoveCnt(useIdx + 1, use[useIdx], openedSecond), abs(use[useIdx] - openedSecond) + minMoveCnt(useIdx + 1, openedFirst, use[useIdx]));
    dp[useIdx][openedFirst][openedSecond] = ret;
    dp[useIdx][openedSecond][openedFirst] = ret;
    return ret;
}

int main() {
    cin >> N;
    int open1, open2;

    cin >> open1 >> open2;

    cin >> useCnt;

    for (int i = 1; i <= useCnt; i++) {
        cin >> use[i];
    }

    cout << minMoveCnt(1, open1, open2) << "\n";
}