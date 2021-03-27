# 2342 Dance Dance Revolution

- https://www.acmicpc.net/problem/2342
- DP
---
- dp[left][right][idx]: 발 위치가 (left, right) 인 상태에서 지시 사항 idx 부터 끝까지 수행하는데 필요한 최소 힘
- dp[left][right][idx] = min(dp[left][target][idx + 1] + cost, dp[target][right][idx + 1] + cost)
