# 11066 파일 합치기

- https://www.acmicpc.net/problem/11066
- DP, Knuth's optimization
---
- dp[i][j]: i + 1 부터 j 파일 합치는데 드는 최소 비용
- dp[i][j] = min(dp[i][k] + dp[k][j]) + c[i][j](i < k < j, c[i][j]: i ~ j 파일 크기 합)
- k 를 i + 1 부터 j - 1 까지 하면 답
- dp 점화식과 c 가 Knuth's optimization 을 적용하기 위한 조건을 만족
- A[i][j]: dp[i][k] + dp[k][j] 값을 최소로 하는 k 값중 최소
- A[i][j - 1] <= A[i][j] <= A[i + 1][j]
    - k 값 찾는 범위 좁힐 수 있음
