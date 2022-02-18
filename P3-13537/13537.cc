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

    vector<vector<long long> > t(2 * N);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        t[N + i].push_back(num);
    }

    for (int i = N - 1; i >= 1; --i) {
        t[i].resize(t[i << 1 | 1].size() + t[i << 1].size());
        merge(all(t[i << 1 | 1]), all(t[i << 1]), t[i].begin());
    }

    auto query = [&](int l, int r, int k) {
        int ret = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret += t[l].end() - upper_bound(all(t[l]), k), ++l;
            if (r & 1) --r, ret += t[r].end() - upper_bound(all(t[r]), k);
        }
        return ret;
    };

    int M;
    cin >> M;
    while (M--) {
        int i, j, k;
        cin >> i >> j >> k;
        cout << query(i - 1, j, k) << '\n';
    }
}