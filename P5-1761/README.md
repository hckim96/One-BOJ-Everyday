# 1761 정점들의 거리

- https://www.acmicpc.net/problem/1761
- Lowest Common Ancestor(LCA), Sparse table
---
- dist(u, v) = distToRoot(u) + distToRoot(v) - 2 * distToRoot(LCA(u, v))
