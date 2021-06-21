#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

void f(vector<vector<int> >& arr, vector<vector<int> >& dp, int W) {
    int N = dp.size();
    
    for (int i = 1; i < N; ++i) {

        dp[i][1] = dp[i - 1][0] + 1;
        dp[i][2] = dp[i - 1][0] + 1;

        if (arr[0][i - 1] + arr[0][i] <= W) {
            dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);
        }

        if (arr[1][i - 1] + arr[1][i] <= W) {
            dp[i][2] = min(dp[i][2], dp[i - 1][1] + 1);
        }

        dp[i][0] = min(dp[i][2] + 1, dp[i][1] + 1);

        if (arr[0][i - 1] + arr[0][i] <= W && arr[1][i - 1] + arr[1][i] <= W) {
            if (i - 2 >= 0) {
                dp[i][0] = min(dp[i][0], dp[i - 2][0] + 2);
            } else {
                dp[i][0] = min(dp[i][0], 2);
            }
        }

        if (arr[0][i] + arr[1][i] <= W) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, W;
        cin >> N >> W;

        // top and bottom, top, bottom
        vector<vector<int> > dp(N, vector<int> (3, INF));
        vector<vector<int> > arr(2, vector<int> (N));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> arr[i][j];
            }
        }

        pair<int, int> firstCol = {arr[0][0], arr[1][0]};
        int answer = INF;

        // 끝 부분과 안 연결
        if (arr[0][0] + arr[1][0] <= W) {
            dp[0][0] = 1;
        } else {
            dp[0][0] = 2;
        }
        dp[0][1] = 1;
        dp[0][2] = 1;
        f(arr, dp, W);
        answer = min(answer, dp[N - 1][0]);

        if (N != 1) {
            // 위 연결
            if (arr[0][0] + arr[0][N - 1] <= W) {
                arr[0][0] = INF;
                dp[0][0] = 2;
                dp[0][1] = 1;
                dp[0][2] = 1;
                f(arr, dp, W);
                arr[0][0] = firstCol.first;
                answer = min(answer, dp[N - 1][2]);
            }

            // 아래 연결
            if (arr[1][0] + arr[1][N - 1] <= W) {
                arr[1][0] = INF;
                dp[0][0] = 2;
                dp[0][1] = 1;
                dp[0][2] = 1;

                f(arr, dp, W);
                arr[1][0] = firstCol.second;
                answer = min(answer, dp[N - 1][1]);
            }

            // 위, 아 연결
            if (arr[0][0] + arr[0][N - 1] <= W && arr[1][0] + arr[1][N - 1] <= W) {
                arr[0][0] = arr[1][0] = INF;
                dp[0][0] = 2;
                dp[0][1] = 1;
                dp[0][2] = 1;
                f(arr, dp, W);
                answer = min(answer, dp[N - 2][0]);
            }
        }

        cout << answer << '\n';
    }
}
