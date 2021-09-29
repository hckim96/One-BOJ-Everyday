#include <iostream>
#include <vector>

using namespace std;

int query(vector<int>& t, int l, int r) {
    int N = t.size() / 2;
    int ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += t[l++];
        if (r & 1) ret += t[--r];
    }
    return ret;
}

void update(vector<int>& t, int p, int v) {
    for (t[p += t.size() / 2] = v; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M;
        cin >> N >> M;
        vector<int> t(2 * (N + M), 0);
        vector<int> height(N + 1, 0);

        for (int i = 0; i < N; ++i) {
            t[N + M + i] = 1;
        }
        for (int i = N + M - 1; i >= 1; --i) {
            t[i] = t[i << 1] + t[i << 1 | 1];
        }

        for (int i = N; i >= 1; --i) {
            height[i] = N - i;
        }
        int top = N - 1;
        
        for (int i = 0; i < M; ++i) {
            int num;
            cin >> num;

            cout << query(t, height[num] + 1, N + M) << ' ';
            update(t, height[num], 0);
            update(t, ++top, 1);
            height[num] = top;
        }
        cout << '\n';
    }
}