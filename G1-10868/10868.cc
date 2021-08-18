#include <iostream>
#include <vector>

using namespace std;

// [l, r)
int f(vector<int>& t, int l, int r) {
    int N = t.size() / 2;

    int ret = 1e9;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ret = min(ret, t[l++]);
        }

        if (r & 1) {
            ret = min(ret, t[--r]);
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;

    vector<int> t(2 * N, 0);

    for (int i = 0; i < N; ++i) {
        cin >> t[N + i];
    }

    for (int i = N - 1; i > 0; --i) {
        t[i] = min(t[i << 1], t[i << 1 | 1]);
    }

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;

        cout << f(t, a - 1, b) << '\n';
    }
}