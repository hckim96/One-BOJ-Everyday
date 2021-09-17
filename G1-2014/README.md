# 2014 소수의 곱

- https://www.acmicpc.net/problem/2014
- Priority queue
---
- pq.top min
- top 에 소수들을 하나씩 곱한 수들을 큐에 넣음
- 중복 제거 방법 (2 * 3, 3 * 2)
    1. 큐에 넣은 수 set 에 넣기
    2. 곱해질 수의 가장 작은 소인수까지만 곱하기