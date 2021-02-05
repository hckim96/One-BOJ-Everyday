#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define INF 987654321

int N, M, C;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    return get<1>(t1) < get<1>(t2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C >> M;

    vector<tuple<int, int, int> > delivery;

    for (int i = 0; i < M; ++i) {
        int n1, n2, c;
        cin >> n1 >> n2 >> c;
        delivery.push_back({n1, n2, c});
    }

    sort(delivery.begin(), delivery.end(), cmp);

    vector<int> capacity(N + 1, C);

    int answer = 0;
    for (auto e: delivery) {
        auto [n1, n2, c] = e;

        int minCapacity = INF;
        for (int i = n1; i < n2; ++i) {
            minCapacity = min(minCapacity, capacity[i]);
        }

        int deliverCnt = min(minCapacity, c);

        answer += deliverCnt;
        for (int i = n1; i < n2; ++i) {
            capacity[i] -= deliverCnt;
        }
    }

    cout << answer << '\n';
}