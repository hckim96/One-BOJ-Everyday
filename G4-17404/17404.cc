#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define N_MAX 1000
#define INF 987654321

int N;
vector<vector<vector<int> > > dp(N_MAX + 1, vector<vector<int> > (3, vector<int> (3, INF)));
int arr[N_MAX + 1][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        for (int c = 0; c < 3; ++c) {
            cin >> arr[i][c];
        }
    }

    dp[1][0][0] = arr[1][0];
    dp[1][1][1] = arr[1][1];
    dp[1][2][2] = arr[1][2];

    for (int f = 0; f < 3; ++f) {
        for (int n = 2; n <= N; ++n) {
            for (int e = 0; e < 3; ++e) {
                for (int pe = 0; pe < 3; ++pe) {
                    if (e == pe) {
                        continue;
                    }

                    dp[n][f][e] = min(dp[n][f][e], dp[n - 1][f][pe] + arr[n][e]);
                }
            }
        }
    }

    int answer = INF;
    for (int f = 0; f < 3; ++f) {
        for (int e = 0; e < 3; ++e) {
            if (f == e) {
                continue;
            }
            answer = min(answer, dp[N][f][e]);
        }
    }

    cout << answer << "\n";
}