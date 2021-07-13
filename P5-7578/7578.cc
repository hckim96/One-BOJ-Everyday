#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> t;

void update(int p, int v) {
    for (t[p += N] += v; p > 1; p >>= 1) {
        t[p >> 1] += v;
    }
}

int query(int l, int r) {
    long long ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ret += t[l++];
        }
        if (r & 1) {
            ret += t[--r];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    t.resize(2 * N, 0);

    vector<int> v(1000001, -1);

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        v[num] = i;
    }

    vector<int> v2(N);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        
        v2[i] = v[num];
    }

    long long answer = 0;

    for (auto e: v2) {
        answer += query(e + 1, N);
        update(e, 1);
    }

    cout << answer << '\n';
}