# 17837 새로운 게임 2

- https://www.acmicpc.net/problem/17837
- Implementation
---
- pieceNumAt[r][c] : {1, 2, 3, ...} 
    - r, c 에 밑에서부터 1, 2, 3 번 말이 놓여져 있음
- 현재 이동할 말의 위치 찾고 그 뒤부터 쭉 옮기면 됨
    - algorithm 의 find
- 이동하려는 칸이 RED 인 경우 위치부터 끝까지 reverse 하고 옮김
