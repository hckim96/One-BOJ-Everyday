#include <iostream>

using namespace std;

int N;

int num[100] = {0};

// 8바이트 사인드, -> 2^ 63 - 1 까지 표현
// 8바이트 언사인드 - > unsigned long long -> 2^ 64 - 1 까지 표현 
// dp[i][j]: i 번째 까지 연산 했을 때, j 수를 만들 수 있는 경우의 수
long long dp[100][21] = {0};

void dpFunction() {

    dp[0][num[0]] = 1;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j < 21; j++) {
            if (dp[i - 1][j] > 0) {
                if (j - num[i] >= 0) {
                    dp[i][j - num[i]] += dp[i - 1][j];
                }
                if (j + num[i] <= 20) {
                    dp[i][j + num[i]] += dp[i - 1][j];
                }
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    dpFunction();

    cout << dp[N - 2][num[N - 1]] << "\n";
}