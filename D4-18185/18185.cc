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
    vector<int> a(N + 2, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        if (!a[i]) continue;

        if (a[i + 1] <= a[i + 2]) {
            int tmp = min({a[i], a[i + 1], a[i + 2]});
            ans += tmp * 7;
            a[i] -= tmp;
            a[i + 1] -= tmp;
            a[i + 2] -= tmp;
            if (!a[i]) continue;

            tmp = min(a[i], a[i + 1]);
            ans += tmp * 5;
            a[i] -= tmp;
            a[i + 1] -= tmp;

            if (!a[i]) continue;

            ans += a[i] * 3;
            a[i] = 0;
        } else {
            int tmp = min(a[i + 1] - a[i + 2], a[i]);
            ans += tmp * 5;
            a[i] -= tmp;
            a[i + 1] -= tmp;

            tmp = min({a[i], a[i + 1], a[i + 2]});
            ans += tmp * 7;
            a[i] -= tmp;
            a[i + 1] -= tmp;
            a[i + 2] -= tmp;

            ans += a[i] * 3;
            a[i] = 0;
        }
    }
    cout << ans << '\n';
}