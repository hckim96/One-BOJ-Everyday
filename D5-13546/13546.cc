#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    vector<long long> a(N);
    for (auto& e: a) {
        cin >> e;
    }

    int M;
    cin >> M;

    vector<tuple<int, int, int> > query(M);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        query[i] = {a, b, i};
    }

    int srqtN = sqrt(N);

    auto cmp = [&](tuple<int, int, int> p1, tuple<int, int, int> p2) {
        return get<0>(p1) / srqtN < get<0>(p2) / srqtN || (get<0>(p1) / srqtN == get<0>(p2) / srqtN && get<1>(p1) < get<1>(p2));
    };

    sort(all(query), cmp);
    
    vector<int> cnt(N, 0), bucket(N / srqtN + 1, 0);
    vector<deque<int> > pos(K + 1);
    auto include = [&](int idx) {
        int prev = -1;
        if (!pos[a[idx]].size()) pos[a[idx]].push_front(idx);
        else if (pos[a[idx]].back() < idx) prev = pos[a[idx]].back() - pos[a[idx]].front(),pos[a[idx]].push_back(idx);
        else prev = pos[a[idx]].back() - pos[a[idx]].front(), pos[a[idx]].push_front(idx);

        if (prev != -1) --cnt[prev], --bucket[prev / srqtN];
        int cur = pos[a[idx]].back() - pos[a[idx]].front();
        ++cnt[cur], ++bucket[cur / srqtN];
    };

    auto exclude = [&](int idx) {
        int prev = pos[a[idx]].back() - pos[a[idx]].front();
        --cnt[prev], --bucket[prev / srqtN];

        if (pos[a[idx]].back() == idx) pos[a[idx]].pop_back();
        else pos[a[idx]].pop_front();

        int cur = -1;
        if (pos[a[idx]].size()) cur = pos[a[idx]].back() - pos[a[idx]].front();

        if (cur != -1) ++cnt[cur], ++bucket[cur / srqtN];
    };

    auto getMax = [&]() {
        for (int i = bucket.size() - 1; i >= 0; --i) {
            if (!bucket[i]) continue;
            for (int j = (i + 1) * srqtN - 1; j >= i * srqtN; --j) {
                if (j >= cnt.size()) continue;
                if (!cnt[j]) continue;
                return j;
            }
        }
        return -1;
    };

    auto [l, r, idx] = query[0];
    for (int i = l; i <= r; ++i) {
        include(i);
    }

    vector<int> ans(M);
    for (auto [ll, rr, i]: query) {
        while (l > ll) include(--l);
        while (r < rr) include(++r);
        while (l < ll) exclude(l++);
        while (r > rr) exclude(r--);
        ans[i] = getMax();
    }
    for (auto e: ans) {
        cout << e << '\n';
    }
}