# 1707 이분 그래프

- BFS, Bipartite graph
- 인접 정점의 색을 다르게(다른 그룹으로) (visited 1, -1) 
- 체크: 모든 변에 대해 두 정점 그룹이 다르면 bipartite graph
- 연결되지 않은 정점 있을 수도 있으므로 모든 정점에서 visited 체크 후 bfs 출발
