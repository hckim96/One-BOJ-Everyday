#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int M, N;
    cin >> M >> N;

    vector<int> v(2 * M, 0);

    while (N--) {
        int cnt0, cnt1, cnt2;
        cin >> cnt0 >> cnt1 >> cnt2;
        ++v[cnt0];
        ++v[cnt0 + cnt1];
    }

    vector<int> pv(2 * M - 1, 0);

    for (int i = 0; i < pv.size(); ++i) {
        pv[i] = v[i];
        if (i) pv[i] += pv[i - 1];
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j) cout << pv[M - 1 + j] + 1 << ' ';
            else cout << pv[M - 1 - i] + 1 << ' ';
        }
        cout << '\n';
    }
}