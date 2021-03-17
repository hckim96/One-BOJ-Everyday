# 1958 LCS 3

- https://www.acmicpc.net/problem/1958
- Longest Common Subsequence(LCS), DP
---
- LCS[i][j][k]: s1 i 인덱스, s2 j 인덱스, s3 k 인덱스 까지 LCS 의 길이
- LCS[i][j][k] = 
    1. (s1[i] == s2[j] == s3[k]) ? LCS[i - 1][j - 1][k - 1] + 1
    2. : max(LCS[i - 1][j][k], LCS[i][j - 1][k], LCS[i][j][k - 1])