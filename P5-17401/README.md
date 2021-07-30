# 17401	일하는 세포

- https://www.acmicpc.net/problem/17401
- Exponentiation by squaring
---
- 인접행렬 곱셈을 이용하여 경로 수 찾기
    - 혈관 지도 adj*(1번부터 T번까지)
    - 답 행렬은 (adj1 * adj2 * ... * adjT * adj1 * adj2 * ...) (D 개)
    - (adj1 * adj2 * ... * adjT) ^ (D / T) 부분을 로그 복잡도로 구함
