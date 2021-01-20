# 2056 작업

- https://www.acmicpc.net/problem/2056
- Topological sorting, DP
---
- timeNeeded[i] : i 번 작업 소요 시간
- dp[i] : i 번째까지 작업했을 때 걸린 최대 시간
- dp[i] = max(dp[i*]) + timeNeeded[i] (i*: i 보다 선행되어야 하는 작업, dp[i] 는 i보다 선행되는 작업들의 dp 값 중 최대 + i 작업 소요 시간)
- 이 문제에선 어떤 작업의 선행 작업으로 가능한 것의 index 가 그 작업 index 보다 작은 관계이기 때문에 작은 인덱스 부터 차례대로 계산해나갈 수 있음
- 위 관계가 없으면 topological sorting 하면서 dp를 구해야 함
