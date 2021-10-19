# 20193 화려한 정사각형

- https://www.acmicpc.net/problem/20193
- Sweeping, Set, Lazy propagation, Parametric search
---
- check(r): 정사각형 한 변 r 일 때 가능?
    - 정답 R 기준으로 결과가 이분적
    - parametric search
- check(r)
    - x 좌표 작은 순서대로 sweeping
    - 매 순간 x 좌표 차이가 r 이하인 점들만 들어가게 유지
    - k 색에 대해 y 값 구간 더함
    - 한 색에 대해 겹치면 합집합으로 처리해주어야 하므로 lower_bound 로 세그먼트 트리에서 처리해줄 l, r 구함