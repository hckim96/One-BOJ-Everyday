# 9465 스티커

- https://www.acmicpc.net/problem/9465
- DP
---
- dp[i][j]: i, j 위치 스티커 마지막으로 뗏을 때 최대 점수
- dp[i][j] = 가로 1칸 대각선, 가로 2칸 대각선 위치 중 dp 값 큰 것과 i, j 스티커 점수 더한 값
