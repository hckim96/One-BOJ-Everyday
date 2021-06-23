# 2261 가장 가까운 두 점

- https://www.acmicpc.net/problem/2261
- Divide and conquer, Sweeping
---
- f(s, e): 구간 [s, e] 에서 가장 가까운 두 점의 거리제곱의 최소
    1. 두 점 모두 왼쪽 구간에 있는 경우 f(s, mid)
    2. 두 점 모두 오른쪽 구간에 있는 경우 f(mid + 1, e)
    3. 두 점이 왼쪽, 오른쪽 구간에 하나씩 있는 경우
