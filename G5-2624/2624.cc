#include <iostream>

using namespace std;

#define T_MAX 10000
#define k_MAX 100

int dp[T_MAX + 1][k_MAX] = {0};

// value, number
pair<int, int> coin[k_MAX];

int T, k;

int main() {

    cin >> T;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int tmpP, tmpN;

        cin >> tmpP >> tmpN;

        coin[i] = {tmpP, tmpN};
    }

    for (int j = 0; j < k; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= T; i++) {
        if (i % coin[0].first == 0 && i / coin[0].first <= coin[0].second ) {
            dp[i][0] = 1;
        }
    }

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j < k; j++) {
            
            int value = coin[j].first;
            int number = coin[j].second;

            int k = 0;

            // k 번째 동전 사용하지 않고 그 차이만큼 k - 1 번째 까지의 동전들로만 구성하는 경우의 수 더하기
            while (k <= number && value * k <= i) {

                dp[i][j] += dp[i - value * k][j - 1];

                k++;
            }
        }
    }

    cout << dp[T][k - 1] << "\n";
}