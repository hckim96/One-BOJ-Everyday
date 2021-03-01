# 11660 구간 합 구하기 5

- https://www.acmicpc.net/problem/11660
- DP, Prefix sum
---
- sum[i][j]: (1, 1)부터 (i, j) 까지 합
- sum[i][j]: sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j]
