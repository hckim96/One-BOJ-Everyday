#include <iostream>
#include <vector>

using namespace std;

int N;
int h;
vector<long long> d;
vector<long long> t;

void apply(int p, long long value, int children) {
    t[p] += value * children;
    if (p < N) d[p] += value;
}

void build(int p) {
    long long children = 1;
    while (p > 1) {
        p >>= 1;
        children <<= 1;
        t[p] = t[p << 1] + t[p << 1 | 1] + children * d[p];
    }
}

void push(int p) {
    for (int s = h; s > 0; --s) {
        int i = p >> s;
        if (d[i] != 0) {
            int children = 1 << (s - 1);
            apply(i<<1, d[i], children);
            apply(i<<1|1, d[i], children);
            d[i] = 0;
        }
    }
}

void inc(int l, int r, long long value) {
    l += N, r += N;
    int l0 = l, r0 = r;
    for (int children = 1; l < r; l >>= 1, r >>= 1, children <<= 1) {
        if (l&1) apply(l++, value, children);
        if (r&1) apply(--r, value, children);
    }
    build(l0);
    build(r0 - 1);
}

long long query(int l, int r) {
    l += N, r += N;
    push(l);
    push(r - 1);
    long long res = 0;
    for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    h = sizeof(int) * 8 - __builtin_clz(N);
    t.resize(2 * N, 0);
    d.resize(N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> t[N + i];
    }

    for (int i = N - 1; i > 0; --i) {
        t[i] = t[i << 1] + t[i << 1 | 1];
    }

    int tmp = M + K;
    while (tmp--) {
        long long a, b, c, value;

        cin >> a >> b >> c;
        if (a == 1) {
            cin >> value;
            inc(b - 1, c, value);
        } else {
            cout << query(b - 1, c) << '\n';            
        }
    }
}