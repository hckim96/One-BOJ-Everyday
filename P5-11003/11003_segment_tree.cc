#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int query(vector<int>& t, int l, int r) {
    int N = t.size() / 2;

    int res = INF;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, t[l++]);
        if (r & 1) res = min(res, t[--r]); 
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> t(2 * N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> t[N + i];
    }

    for (int i = N - 1; i > 0; --i) {
        t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

    for (int i = 0; i < N; ++i) {
        int l = i - L + 1 <= 0 ? 0 : i - L + 1;
        cout << query(t, l, i + 1) << ' ';
    }
    cout << '\n';
}