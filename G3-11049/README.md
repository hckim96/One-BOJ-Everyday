# 11049 행렬 곱셈 순서

- https://www.acmicpc.net/problem/11049
- DP
---
- dp[i][j] : 행렬 i ~ j 까지 최소 곱셈 연산 횟수
- dp[i][j] = min(dp[i][k] + dp[k + 1][j] + 곱 비용)
- 곱 비용이 k 에 따라서 달라지므로 Knuth's optimization 적용할 수 없음
