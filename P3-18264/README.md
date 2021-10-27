# 18264 Moortal Cowmbat

- https://www.acmicpc.net/problem/18264
- DP, Floyd-Warshall algorithm, Prefix sum
---
- 알파벳 i 에서 알파벳 j 로 바꾸는 최소 시간 구함(Floyd-Warshall)
- cost2[i][j] = s[i] 를 알파벳 j 로 바꾸는 시간
- pCost2[i][j] = sum(cost2[0...i][j]) (0~i 를 알파벳 j 로 바꾸는 시간)
- dp[i][j]: 인덱스 i 까지 valid 하고 알파벳 j 로 끝나는 경우 최소 시간
- dpMin[i]: 인덱스 i 까지 valid 한 최소시간
- dp[i][j] = min(
    - dp[i - 1][j] + cost2[i][j] // j 로 끝나는 거에 j 붙이기
    - , dpMin[i - K] + pCost2[i][j] - pCost2[i - K][j]) // k 개 j 붙이기
