#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<long long> x(N);
    // x, a
    vector<pair<long long, long long> > v(N);

    long long aSum = 0, axSum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i].second >> v[i].first;
        aSum += v[i].second;
        axSum += v[i].second * v[i].first;
        x[i] = v[i].first;
    }
    sort(v.begin(), v.end());
    sort(x.begin(), x.end());

    vector<long long> c(N + 1, 0), d(N + 1, 0);
    c[N] = aSum;
    d[N] = axSum;
    for (int i = N - 1; i >= 0; --i) {
        c[i] = c[i + 1] - 2 * v[i].second;
        d[i] = d[i + 1] - 2 * v[i].second * v[i].first;
    }

    while (Q--) {
        long long q;
        cin >> q;
        auto it = lower_bound(x.begin(), x.end(), q);
        int idx = it - x.begin();

        cout << c[idx] * q - d[idx] << '\n';
    }

}