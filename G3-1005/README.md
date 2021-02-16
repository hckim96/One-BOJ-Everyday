# 1005 ACM Craft

- https://www.acmicpc.net/problem/1005
- Topological sorting, DP
---
1. indegree 0 인 노드 큐 삽입
2. 큐 빌 때까지
    1. 노드에서 나가는 간선 제거
    2. 그 간선으로 도착하는 노드 indegree 0 이면 큐 삽입
- time[n]: n 노드까지 수행했을 때 총 걸린 시간
- time[n] = max(time[v*]) + D[n] (v*: n의 한단계 선행 작업들)
