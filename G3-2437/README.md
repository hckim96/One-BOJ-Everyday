# 2437 저울

- https://www.acmicpc.net/problem/2437
- Greedy algorithm, Sorting
---
1. 1 부터 측정할 수 없는 수 찾기
    - 무게 오름차순으로 정렬
2. arr[n + 1] 까지 사용해서 측정 가능한 수들은 arr[n] 까지만 사용해서 측정 가능한 수들과 그 수들에 arr[n + 1] 더한 수들 
- S[n] = arr[1] + ... + arr[n] 이라하면, arr[n] 까지 사용해서 측정 가능한 수들의 최대는 S[n]
- arr[n] 까지 사용해서 1 ~ S[n] 측정가능할 때
    - arr[n + 1] > S[n] + 1 이면 arr[n + 1] 까지 사용해서 측정 가능 범위는 1 ~ S[n] 과 arr[n + 1] ~ S[n + 1]
        - S[n] + 1 ~ arr[n + 1] - 1 측정 불가
    - arr[n + 1] <= S[n] + 1 이면 arr[n + 1] 까지 사용해서 측정 가능 범위는 1 ~ S[n + 1]
    