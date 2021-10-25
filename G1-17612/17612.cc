#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
        auto [e1, k1, id1] = t1;
        auto [e2, k2, id2] = t2;

        if (e1 == e2) return k1 > k2;
        return e1 > e2;
    }
};

bool ccmp(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
    auto [e1, k1, id1] = t1;
    auto [e2, k2, id2] = t2;

    if (e1 == e2) return k1 > k2;
    return e1 < e2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    // s, e, k, id
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, cmp> pq;

    int idx = 0;
    for (int i = 1; i <= K; ++i) {
        if (idx >= N) {
            break;
        }
        int id, w;
        cin >> id >> w;
        pq.push({w, i, id});
        ++idx;
    }

    int time = 0;
    vector<tuple<int, int, int> > ret(N);
    int retIdx = 0;
    while (!pq.empty()) {
        auto [e, k, id] = pq.top();
        pq.pop();

        time = e;
        if (idx < N) {
            ++idx;
            int nid, nw;
            cin >> nid >> nw;
            pq.push({time + nw, k, nid});
        }
        ret[retIdx++] = {e, k, id};
    }

    sort(ret.begin(), ret.end(), ccmp);

    long long answer = 0;
    long long tmp = 1;
    for (auto [e, k, id]: ret) {
        answer += (tmp++) * id;
    }
    cout << answer << '\n';
}