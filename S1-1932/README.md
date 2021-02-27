# 1932 정수 삼각형

- https://www.acmicpc.net/problem/1932
- DP
---
- dp[i][j]: i, j 까지 도달 경로 합 최대
- dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i - 1][j - 1] + arr[i][j]);
