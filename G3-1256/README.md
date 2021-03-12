# 1256 사전

- https://www.acmicpc.net/problem/1256
- DP, Combinatorics
---
- 맨 처음 위치에 a 가 있는 경우의 수보다 K 가 크면 맨 처음은 z, 작거나 같으면 a
    - 다음 위치 넘어가면서 반복
- combination(200, 100) > 2^100  (overflow 나서 K 와 비교가 잘못될 수 있음), K < 1e9  이므로 조합 중 1e9 보다 큰 값은 1e9 로 만듬
