# 11062 카드 게임

- https://www.acmicpc.net/problem/11062
- DP, Game theory
---
- dp[turn][leftIdx][rightIdx]: 왼쪽 끝, 오른쪽 끝이 leftIdx, rightIdx 이고 뽑을 사람이 turn 이며 서로 최적의 선택을 한다고 가정했을 때 1 사람이 얻을 수 있는 최대 점수
- dp[1][leftIdx][rightIdx] = max(card[leftIdx] + dp[0][leftIdx + 1][rightIdx], card[rightIdx] + dp[0][leftIdx][rightIdx - 1])
- dp[0][leftIdx][rightIdx] = min(dp[1][leftIdx + 1][rightIdx], dp[1][leftIdx][rightIdx - 1])
