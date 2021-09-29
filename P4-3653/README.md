# 3653 영화 수집

- https://www.acmicpc.net/problem/3653
- Segment tree
---
- 높이 0 에 N 번, 높이 1 에 N - 1 번, ..., 높이 N - 1 에 1 번이 있다 하자
- 위로 올릴 때 가장 위에 있는 번호의 높이의 + 1 로 옮긴다
- 필요한 높이 구간은 0 ~ N + M - 1
- 각 높이에 대하여 DVD 가 있으면 1
- 한 DVD 위에 있는 DVD 수는 query(h[i] + 1, N + M - 1)