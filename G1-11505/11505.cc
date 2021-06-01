#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000007

int N;

// [l, r)
int query(vector<int>& t, int l, int r) {
    int ret = 1;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ret = 1LL * ret * t[l++] % MOD;
        }
        if (r & 1) {
            ret = 1LL * ret * t[--r] % MOD;
        }
    }
    return ret;
}

void modify(vector<int>& t, int p, int value) {
    for (t[p += N] = value; p > 1; p >>= 1) {
        t[p >> 1] = 1LL * t[p] * t[p ^ 1] % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, K;
    cin >> N >> M >> K;

    vector<int> t(2 * N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> t[N + i];
    }

    for (int i = N - 1; i > 0; --i) {
        t[i] = 1LL * t[i << 1] * t[i << 1 | 1] % MOD;
    }
    
    M += K;

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            modify(t, b - 1, c);
        } else {
            cout << query(t, b - 1, c) << '\n';
        }
    }
}
