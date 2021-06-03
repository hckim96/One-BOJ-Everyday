# 13977 이항 계수와 쿼리

- https://www.acmicpc.net/problem/13977
- Fermat's little theorem, Combinatorics, Exponentiation by squaring
---
- 나머지연산 나눗셈에 대해 분배법칙 성립안함
- 페르마 소정리: (a ^ (p - 1)) % p = 1 (p는 소수)
- a / b % p = (a / b * b ^ (p - 1)) % p = (a * b ^ (p - 2)) % p
