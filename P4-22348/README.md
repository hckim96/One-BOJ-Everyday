# 22348 헬기 착륙장

- https://www.acmicpc.net/problem/22348
- DP, Prefix sum
---
- dp[i][j] = 1 ~ i 까지 수를 이용해서 합이 j 가 되게 하는 경우의 수
- dp[i][j] = dp[i - 1][j - i] + dp[i - 1][j];
    - i 쓸 경우, i 안 쓸 경우
- dpSum[i][j] = dp[i][0] + dp[i][1] + ... + dp[i][j]
    - i 로 합 j 이하로 만드는 경우의 수
- a, b 써서 겉 반지름 r 만드는 경우의 수 = dpSum[r][a] - dpSum[r][b*]
    - b* = 크기 r 로 만들 때의 total - b - 1
