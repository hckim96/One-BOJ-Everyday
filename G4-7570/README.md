# 7570 줄 세우기

- https://www.acmicpc.net/problem/7570
- DP, Greedy algorithm, LIS
---
- 1씩 증가하는 LIS 를 제외한 수들을 앞이나 뒤로 순서에 맞게 움직임
- dp[n]: n 으로 끝나는 1씩 증가하는 LIS 길이
- dp[n] = dp[n - 1] + 1
