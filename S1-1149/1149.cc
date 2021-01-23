#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define N_MAX 1000
#define INF 987654321

int arr[N_MAX][3] = {0};
int N;
vector<vector<int> > dp(N_MAX, vector<int> (3, INF));
int answer = INF;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int i = 1; i < N; i++) {
        for (int prev = 0; prev < 3; prev++) {
            for (int cur = 0; cur < 3; cur++) {
                if (prev == cur) {
                    continue;
                }
                dp[i][cur] = min(dp[i][cur], dp[i - 1][prev] + arr[i][cur]);
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        answer = min(answer, dp[N - 1][i]);
    }
    cout << answer << "\n";
}