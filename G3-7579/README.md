# 7579 앱

- https://www.acmicpc.net/problem/7579
- DP, Knapsack
---
- dp[i][c]: i번째 앱까지 고려했을 때 c 비용으로 최대 확보 가능한 memory
- dp[i][c] = max(dp[i - 1][c - cost[i]] + memory[i], dp[i - 1][c])
    - i번째 앱 비활성화 한 경우, i번째 앱 비활성화 안한 경우 중 최대
- i 가 증가하면서 dp 를 채우는데 i 에 대해 i - 1 에 대한 dp 만 필요하므로 1차원 배열로 가능
