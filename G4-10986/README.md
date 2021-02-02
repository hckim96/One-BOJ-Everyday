# 10986 나머지 합

- https://www.acmicpc.net/problem/10986
- Prefix sum
---
- sum[i]: A[1] + ... + A[i]
- (sum[j] - sum[i - 1]) % M = 0
- <==> (sum[j] % M - sum[i - 1] % M) % M = 0
- <==> sum[j] % M = sum[i - 1] % M
- mod M 값이 같은 두 sum 찾기
- sum[k] % M = 0 이면 다른 sum 안 빼도 조건 만족하므로 이 경우도 더해줌
