#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int TC; cin >> TC;
  while (TC--) {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> e(N);
    for (auto& ee: e) cin >> ee;

    vector<vector<vector<int> > > dp(N + 1, vector<vector<int> > (M + 1, vector<int> (R + 1, -1)));

    dp[0][0][0] = 0;

    for (int i = 1; i < N + 1; ++i) {
      for (int j = 0; j < M + 1; ++j) {
        for (int k = 0; k < R + 1; ++k) {
          if (dp[i - 1][j][k] == -1) continue;
          if (j == M) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k]);
            continue;
          }

          if (k == R) {
            dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k]);
            continue;
          }

          dp[i][j + 1][k + 1] = max(dp[i][j + 1][k + 1], dp[i - 1][j][k] + (k + 1) * e[i - 1]);
          dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][k]);
        }
      }
    }

    int ans = -1;

    for (int k = 0; k < R + 1; ++k) {
      ans = max(ans, dp[N][M][k]);
    }
    if (ans == -1) {
      cout << "impossible\n";
    } else {
      cout << ans << '\n';
    }
  }
}