#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;
    vector<int> a(N);
    for (auto& e: a) {
        cin >> e;
    }
    
    int M;
    cin >> M;
    vector<tuple<int, int, int> > query(M);
    for (int i = 0; i < M; ++i) {
        int l, r;
        cin >> l >> r;
        query[i] = {l - 1, r - 1, i};
    }
    int sqrtN = sqrt(N);

    auto cmp = [&](tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
        return get<0>(t1) / sqrtN < get<0>(t2) / sqrtN || (get<0>(t1) / sqrtN == get<0>(t2) / sqrtN && get<1>(t1) < get<1>(t2));
    };

    sort(all(query), cmp);

    vector<int> cnt(1e5 + 1, 0);
    vector<int> ccnt(N + 1, 0);
    int l = 1;
    int r = 0;
    
    int maxCnt = 0;

    auto include = [&](int num) {
        --ccnt[cnt[num]];
        ++cnt[num];
        ++ccnt[cnt[num]];
        maxCnt = max(maxCnt, cnt[num]);
    };
    auto exclude = [&](int num) {
        --ccnt[cnt[num]];
        --cnt[num];
        ++ccnt[cnt[num]];
        if (!ccnt[maxCnt]) {
            maxCnt = cnt[num];
        }
    };

    vector<int> answer(M);
    for (auto& [i, j, ai]: query) {
        while (i < l) include(a[--l]);
        while (i > l) exclude(a[l++]);
        while (j < r) exclude(a[r--]);
        while (j > r) include(a[++r]);
        answer[ai] = maxCnt;
    }
    for (auto& e: answer) {
        cout << e << '\n';
    }
}