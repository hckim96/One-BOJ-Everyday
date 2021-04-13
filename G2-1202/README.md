# 1202 보석 도둑

- https://www.acmicpc.net/problem/1202
- Greedy algorithm
---
1. 보석 기준
    - 가치 큰 보석 순서대로 훔칠지 말지 결정하는데 넣을 수 있는 가방 중 최대 무게가 가장 작은 것에 넣음
    - std::lower_bound 는 non-random-access iterator 인 set 의 bidirectional iterator 에 대해서는 시간적으로 비효율적이므로 std::set::lower_bound 씀
2. 가방 기준
    - 최대 무게 작은 가방부터 해당 가방에 넣을 수 있는 보석들 중 가장 가격이 높은 것을 넣음
