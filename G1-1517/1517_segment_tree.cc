#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int query(vector<int>& t, int l, int r) {
    int N = t.size() / 2;

    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }

    return res;
}

void increase(vector<int>& t, int p, int v) {
    for (p += t.size() / 2; p > 0; p >>= 1) t[p] += v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> t(2 * N, 0);
    vector<pair<int, int> > arr(N);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        arr[i] = {num, i};
    }
    
    sort(arr.begin(), arr.end());

    long long answer = 0;

    for (auto [num, idx]: arr) {
        answer += query(t, idx + 1, N);
        increase(t, idx, 1);
    }

    cout << answer << '\n';
}