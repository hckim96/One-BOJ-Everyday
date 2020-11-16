#include <iostream>

using namespace std;

#define DIGIT_MAX 64

int T, N;

// 자리수, 끝나는 수
long long dp[DIGIT_MAX + 1][10] = {0};

int main() {
    cin >> T;

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    while(T--) {
        cin >> N;
        long long cnt = 0;
        for (int digit = 1; digit <= N; digit++) {
            for (int i = 0; i < 10; i++) {
                if (dp[digit][i] != 0) {
                    continue;
                }

                for (int j = i; j < 10; j++) {
                    dp[digit][i] += dp[digit - 1][j];
                }
            }
        }

        for (int i = 0; i < 10; i++) {
            cnt += dp[N][i];
        }
        cout << cnt << "\n";
    }
}