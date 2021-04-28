# 9527 1의 개수 세기

- https://www.acmicpc.net/problem/9527
- Math, Prefix sum, DP
---
- dp[i]: i 개의 비트로 나타낼 수 있는 수들의 1의 개수 합
- dp[i] = dp[i - 1] + (dp[i - 1] + 2^(i - 1)) (i - 1 개 비트 앞 0인 경우 +  1 인 경우)
- S(num): num 까지 1 개수
