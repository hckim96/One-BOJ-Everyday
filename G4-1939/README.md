# 1939 중량제한

- https://www.acmicpc.net/problem/1939
- BFS, Binary search
1. 다리의 중량제한 중 최대 값 저장
2. low = 0, high = 다리 중량 제한의 최대 값, 으로 두고 이분탐색으로 출발지에서 도착지까지 이동 가능 한 가장 큰 중량을 찾음
3. 이동 가능 한지 여부는 bfs로 알아냄
