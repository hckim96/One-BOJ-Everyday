# 2698 인접한 비트의 개수

- https://www.acmicpc.net/problem/2698
- DP
---
- dp[e][n][k]: 끝이 e 로 끝나고 크기 n 인접비트 k 인 수열의 개수
    - dp[0][n][k] = dp[1][n - 1][k] + dp[0][n - 1][k];
    - dp[1][n][k] = (k == 0 ? 0 : dp[1][n - 1][k - 1]) + dp[0][n - 1][k];
