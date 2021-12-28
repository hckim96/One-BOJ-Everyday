#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    reverse(all(a));

    vector<int> dp;
    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(all(dp), a[i]);
        if (it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            *it = a[i];
        }
    }
    cout << dp.size() << '\n';
}