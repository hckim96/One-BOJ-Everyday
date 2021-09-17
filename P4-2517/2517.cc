#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.second < p2.second;
}

int query(vector<int>& t, int l, int r) {
    int N = t.size() / 2;

    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }

    return res;
}

void inc(vector<int>& t, int p) {
    int N = t.size() / 2;
    for (t[p += N] += 1; p > 1; p >>= 1) t[p >> 1] = t[p ^ 1] + t[p];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;    
    vector<pair<int, int> > v(N);

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        v[i] = {num, i};
    }

    sort(v.begin(), v.end());

    vector<int> t(2 * N, 0);

    vector<int> answer(N);
    for (auto [num, idx]: v) {
        answer[idx] = idx + 1 - query(t, 0, idx);
        inc(t, idx);
    }

    for (auto e: answer) {
        cout << e << '\n';
    }
}