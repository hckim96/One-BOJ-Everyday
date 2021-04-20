# 2098 외판원 순회

- https://www.acmicpc.net/problem/2098
- DP, Bitmasks
---
- dp[cur][stat]: 방문 정점 정보가 stat 이고 현재 cur 에 있을 때 순회 완료까지 드는 비용의 최소
- 한 정점에서 최소 비용의 순회 싸이클 존재하면 다른 정점의 최소 비용 순회 싸이클도 그것과 같음
- dp 경우의 수 N * 2 ^ N * 한 경우의 수마다 연결점 O(N) -> O(N * 2 ^ N * N)
