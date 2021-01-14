# 1956 운동

- https://www.acmicpc.net/problem/1956
- Floyd-Warshall algorithm
---
1. 입력제외 distance : overflow 안 날 정도의 INF
2. Floyd-Warshall algorithm
3. 각 노드에 대해 distance[i][i] 가 INF 가 아니면 사이클이 존재하고 그 값이 최소값임
4. distance[i][i] 중 최소가 답
