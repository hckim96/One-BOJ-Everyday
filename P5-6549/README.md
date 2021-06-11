# 6549 히스토그램에서 가장 큰 직사각형

- https://www.acmicpc.net/problem/6549
- Divide and conquer, Segment tree
---
- f(l, r): [l, r)  구간에서 가장 큰 직사각형 넓이
- f(l, r) = max(f(l, minHeightIdx), f(minHeightIdx + 1, r), (r - l) * height[minHeightIdx])
