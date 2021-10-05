# 22345 누적 거리

- https://www.acmicpc.net/problem/22345
- Binary search, Sorting
---
- 모임 장소가 제일 클 때
    - f(x) = (a1 + ... + an) * x - (a1x1 + ... + anxn)
- 한 마을보다 작을 때
    - f(x) = (a1 + ... + (an-1) - an) * x - (a1x1 + ... + (an-1xn-1) - anxn)
