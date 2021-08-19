# 11401 이항 계수 3

- https://www.acmicpc.net/problem/11401
- Exponentiation by squaring, Fermat's little theorem
---
- Combination(N, K) % MOD 
- = N!/(K! * (N - K)!) % MOD
- = (N * ... * N - K + 1 ) * (ModularMultiplicativeInverse(K * K - 1 * ... * 1)) % MOD