# 1655 가운데를 말해요

- https://www.acmicpc.net/problem/1655
- Priority queue
---
- 중간값이하인 부분과 초과인 부분을 maxHeap, minHeap 으로 나누어서 관리
- 말한 수 정렬했을 때 중간값 포함한 앞부분을 maxHeap, 뒷부분을 minHeap
    - maxHeap.top() 이 중간값, minHeap.top() 은 뒷부분 중 가장 작은 값
- maxHeap.size() - minHeap.size() = 1, 0, 1, 0, 1, 0, ...
