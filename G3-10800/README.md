# 10800 컬러볼

- https://www.acmicpc.net/problem/10800
- Prefix sum, Sorting
---
- ball: {size, color, player}
- colorSum[c]: c 색 가진 공 사이즈 누적 합
- ball 오름차순 정렬
- ball 처음 원소부터 끝까지
    - player 가 잡을 수 있는 공 사이즈 합: 이전 원소까지 누적합 - colorSum[해당 공 색]
- 크기가 같은 경우 이전 사이즈 기준으로 계산해줘야 하므로 이전 값 저장
