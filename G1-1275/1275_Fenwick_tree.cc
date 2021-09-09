#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<long long>& t, int p) {
    long long res = 0;
    while (p > 0) {
        res += t[p];
        p -= (p & -p);
    }
    return res;
}

void add(vector<long long>& t, int p, long long diff) {
    while (p < t.size()) {
        t[p] += diff;
        p += (p & -p);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<long long> t(N + 1, 0);
    vector<long long> arr(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        add(t, i, arr[i]);
    }
    while (Q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > b) swap(a, b);

        cout << sum(t, b) - sum(t, a - 1) << '\n';
        
        long long diff = d - arr[c];
        arr[c] = d;
        add(t, c, diff);
    }
}