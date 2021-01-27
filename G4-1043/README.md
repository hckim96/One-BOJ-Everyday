# 1043 거짓말

- https://www.acmicpc.net/problem/1043
- Graph traversal, Disjoint set
---
1. Graph traversal
    - 진실 아는 사람 큐에 넣음
    - 사람별 가는 파티, 파티별 있는 사람 저장
    - 큐 빌 때까지: 큐에 있는 사람 파티는 거짓말 못함, 그 파티 안에 있는 사람 큐에 넣음
2. Disjoint set
    - 진실 아는 사람들 한 집합
    - 각 파티별 사람들 한 집합
    - 각 파티 집합이 진실 아는 집합과 다르면 거짓말 가능
