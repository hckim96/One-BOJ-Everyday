# 17612 쇼핑몰

- https://www.acmicpc.net/problem/17612
- Priority queue
---
- pq 에 [e, k, id] 관리
    - e: 끝나는 시간
    - k: 계산한 계산대 번호
    - id: 회원 번호
    - e 작은순, 같으면 k 작은순으로 pop, push
- 나올 때 k 큰 순으로 나와야 하므로 ret 배열 정렬 한번 해줌