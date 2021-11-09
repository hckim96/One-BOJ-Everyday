#include <bits/stdc++.h>

using namespace std;

enum {
    UP,
    DOWN
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    pair<long long, long long> prev = {-1e9 - 1, 0};

    deque<tuple<long long, long long, int> > dq;
    pair<long long, long long> first;
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        if (i == 0) first = {x, y};
        if (x == prev.first && prev.second * y < 0) dq.push_back({x, y > 0 ? UP: DOWN, 0});
        prev = {x, y};
    }
    if (first.first == prev.first && prev.second * first.second < 0) dq.push_back({first.first, first.second > 0 ? UP: DOWN, 0});
    
    assert(dq.size() % 2 == 0);
    if (get<1>(dq.front()) == DOWN) {
        dq.push_back(dq.front());
        dq.pop_front();
    }

    int seq = 1;
    for (int i = 0; i < dq.size(); i += 2) get<2>(dq[i]) = get<2>(dq[i + 1]) = seq++;
    sort(dq.begin(), dq.end());

    int prevSeqNum = 0;
    int notIncluded = 0;
    int notInclude = 0;
    int findSeqNum = 0;
    for (auto [x, state, seqNum]: dq) {
        if (prevSeqNum == seqNum) ++notInclude; 
        if (state == UP && !findSeqNum) findSeqNum = seqNum;
        if (state == DOWN && findSeqNum == seqNum) findSeqNum = 0, ++notIncluded;
        prevSeqNum = seqNum;
    }

    cout << notIncluded << ' ' << notInclude << '\n';
}