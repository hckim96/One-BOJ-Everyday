# 2533 사회망 서비스(SNS)

- https://www.acmicpc.net/problem/2533
- DP
---
- dp[root][isEarlyAdapter]: isEarlyAdapter인 root 를 최상위노드로 가지는 트리가 조건 만족하기 위해 필요한 최소 얼리 어답터의 수
- 어떤 노드가 얼리 어답터 아니면 연결된 노드는 무조건 얼리 어답터, 얼리 어답터이면 연결 노드는 얼리 어답터일 수도 아닐 수도 있음
