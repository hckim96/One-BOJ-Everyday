# 1854 K번째 최단경로 찾기

- https://www.acmicpc.net/problem/1854
- Dijkstra's algorithm
---
- 정점마다 최단경로 max heap 으로 K 개까지만 관리
- K 개 미만이면 push 후 다음 경로 찾기
- K 개 이상일 때(K 개) top 보다 지금 찾은 경로가 작으면 지금 top 이 K 이상 번째 이므로 pop 하고 지금 찾은 경로 push
- pq.top 의 d 가 dist[n].top < d 면 dist[n] 이 K 개 이상인 상태이고 d 보다 작은 경로가 push 되어서 d 가 pop 되었다는 의미이므로 볼 필요가 없음
