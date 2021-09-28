# 1305 광고

- https://www.acmicpc.net/problem/1305
- KMP
---
- 광고판에 보여지는 문자열의 길이 - 접두사 접미사 같은 최대 길이 가 답
- KMP 알고리즘의 pi 배열 구하기
    - pi[i]: i 인덱스까지 prefix == suffix 가 될 수 있는 최대 길이, 단 문자열 전체 제외(prefix == suffix == 0 ~ i 인 경우, 최대: i)
    1. 같지않으면 (&& j == 0)
        - j 이동 (원래 j = 0 으로 가야하는데 지금까지 구한 pi 로 불필요한 부분 건너뜀)
    2. 같으면
        - ++j
        - pi[i] = j
