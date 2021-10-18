# 21759 두 개의 팀

- https://www.acmicpc.net/problem/21759
- DP on tree, DFS
---
- team[i]: i 가 팀장인 팀의 점수
- sub[i]: 루트 i 인 서브트리에서 팀의 점수 최대
- maxExclude[i]: 루트 i 인 서브트리에서 i 가 팀장인 팀의 팀원들을 제외한 사원들로 구성 가능한 팀의 점수 최대