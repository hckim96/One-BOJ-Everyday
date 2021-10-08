# 15591 MooTube (Silver)

- https://www.acmicpc.net/problem/15591
- Graph traversal, Disjoint set
---
1. bfs 로 k 이하인 간선만 타고 감
2. k 이상인 간선 두 정점 union 후 v 가 속한 집합의 크기 - 1 
    - k 이상이므로 k 가 큰 query 부터 