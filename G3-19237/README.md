# 19237 어른 상어

- https://www.acmicpc.net/problem/19237
- Implementation
---
- time = 0 에서 시작
- shark[num] : 번호 num 인 상어의 {r, c, direction, isAlive}
- sharkOrder[num][d][order]: 번호 num 인 상어가 현재 d 방향일 때 order 번째 우선순위의 방향
- smell[r][c]: r, c 좌표의 냄새 {sharkNum, leftTime}
- map[r][c]: r, c 좌표의 상어 번호(비었으면 0)
- time 1000 미만일 때
    1. 상어 앞 번호부터 이동
        1. 방향 우선순위 높은 순서대로 냄새 없는 칸 있으면 그 칸으로 이동
            - 냄새 없는 칸인데 상어가 있으면, 작은 번호 상어가 이번 시간에 이동할 위치라는 것이므로 해당 상어 격자 밖으로
        2. 위에서 냄새 없는 칸이 없었으면 방향 우선순위 높은 순서대로 자신 냄새칸으로 이동
    2. 냄새 업데이트
        1. 상어 있는 칸 냄새 갱신
        2. 상어 없지만 냄새 남아 있는 칸 - 냄새 시간 줄임
