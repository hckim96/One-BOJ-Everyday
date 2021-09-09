#include <iostream>
#include <vector>

using namespace std;

long long query(vector<long long>& t, int l, int r) {
    int N = t.size() / 2;
    long long res = 0;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }

    return res;
}

void modify(vector<long long>& t, int p, int v) {
    int N = t.size() / 2;
    for (t[p += N] = v; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<long long> t(2 * N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> t[N + i];
    }
    
    for (int i = N - 1; i > 0; --i) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }

    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > b) swap(a, b);

        cout << query(t, a - 1, b) << '\n';
        modify(t, c - 1, d);
    }
}