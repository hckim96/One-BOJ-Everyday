# 20667 크롬

- https://www.acmicpc.net/problem/20667
- DP, Knapsack
---
- dp[i][cpu][memory] = 최소 중요도 합
    - MLE, TLE
- dp[i][cpu][priority] = 최대 memory 합
- dp[i][memory][priority] = 최대 cpu 합

- dp[i][cpu][priority] = max(dp[i - 1][cpu][priority], dp[i - 1][cpu - cpu[i]][priority - priority[i]] + memory[i]);
    - cpu 가 M 넘어가는 경우를 M 으로