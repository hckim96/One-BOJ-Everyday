# 2517 달리기

- https://www.acmicpc.net/problem/2517
- Segment tree, Value compression
---
- 실력의 상대적인 크기만 필요하므로 실력 순위로
- 실력 작은 선수부터 체크
    - 그 선수 최선의 등수는 원래 위치 - 지금까지 넣은(자신보다 실력 작은) 트리에서 자신 원래 위치보다 앞에 있는 선수의 수
    - 트리에 원래 위치 넣음