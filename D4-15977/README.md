# 15977 조화로운 행렬

- https://www.acmicpc.net/problem/15977
- LIS, LIS on pairs
---
- dp[i]: i + 1 길이 lis의 마지막 원소 최소값
- LIS on pairs
    - p1 < p2  : p1.first < p2.first && p1.second < p2.second
    - 여러개의 최소 값(pair) 가능 : set으로 관리