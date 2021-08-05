# 1014 컨닝

- https://www.acmicpc.net/problem/1014
- DP, Bitmasks
---
- dp[i][stat]: 0 ~ i 행 까지만 고려하고 i 행이 stat 상태일 때 배치 가능한 최대 학생 수
- dp[i][stat] = max(dp[i - 1][pstat*]) + (stat 상태인 행의 학생 수) (pstat* 과 stat 은 컨닝 불가)
- 한 행에서 열에 대해 연속으로 학생을 배치 할 수 없음
- 의자 부서진 곳에는 앉을 수 없음
