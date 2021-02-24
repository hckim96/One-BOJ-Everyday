# 2263 트리의 순회

- https://www.acmicpc.net/problem/2263
- Recursion
---
- printPreorder(postorder, inorder)
    1. 부모노드 출력
    2. printPreorder(left child의 postorder, inorder)
    3. printPreorder(right child의 postorder, inorder)
- postorder 에서 부모노드가 마지막에 있고 inorder 에서 부모노드 왼쪽에 left child, 오른쪽에 right child 가 있음
- postorder 에서 부모노드를 찾고 inorder 에서의 그 부모노드 위치를 찾음
    - inorder 에서 각 노드의 위치를 저장하는 배열으로 탐색 시간 줄일 수 있음
