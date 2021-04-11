# 2662 기업투자

- https://www.acmicpc.net/problem/2662
- DP, Knapsack
---
- dp[n][m]: 총 n 만원 1 ~ m 기업에 투자시 최대 이익
- dp[n][m] = max(dp[n - i][m - 1] + profit[i][m]) (i = 0 ~ n)
