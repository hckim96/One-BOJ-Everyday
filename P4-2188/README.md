# 2188 축사 배정

- https://www.acmicpc.net/problem/2188
- Maximum flow, Bipartite matching
---
- Maximum flow
    - 방문 여부를 prev 가 nullptr 인 지로 판단하는데, 처음으로 방문해서 prev 가 nullptr 인 S 는 따로 체크를 해주어야함
- Bipartite matching
    - 두 그룹으로 나눠서 한 그룹 기준으로 하나씩 매칭 시도
    - 매칭 시도
        - 연결되어 있는 정점이 매칭이 안되어있으면 매칭
        - 매칭 되어있으면 그 정점과 매칭되어 있는 정점을 다른 점으로 다시 매칭 시도하고 성공시 매칭 변경
