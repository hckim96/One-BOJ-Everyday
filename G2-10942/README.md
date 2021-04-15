# 10942 팰린드롬?

- https://www.acmicpc.net/problem/10942
- DP
---
- dp[s][e]: s ~ e 수열이 팰린드롬인지
- dp[s][e] = dp[s + 1][e - 1] && (arr[s] == arr[e])
