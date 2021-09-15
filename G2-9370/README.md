# 9370 미확인 도착지

- https://www.acmicpc.net/problem/9370
- Dijkstra's algorithm
---
- 최단경로가 S ~ G - H ~ E 이거나 S ~ H - G ~ E
- 최단경로가 G - H 지나는 경로, 안지나는 경로 모두 있을 수 있음
- S ~ P1 - P2 ~ E 가 최단경로이면 S 에서 P1 거리가 P2 까지 거리보다 가까움 (P1, P2 는 G 또는 H)
- S 에서 P1 까지 거리 + P1-P2 + P2 에서 E 까지 거리
    - 다익스트라 두번