#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<pair<int, int>, int> dp;

int f(int l, int r) {
    if (dp.count({l, r})) return dp[{l, r}];

    int ret = 0;
    for (int i = 1; (1 << i) - 1 <= 1e9; ++i) {
        int nl = (1 << i) - 1;
        int nr = (1 << (i + 1)) - 2;

        nl = max(nl, l);
        nr = min(nr, r);

        if (nl <= nr) {
            ret = max(ret, i + f(nl - (1 << i) + 1, nr - (1 << i) + 1));
        }
    }
    return dp[{l, r}] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    dp[{0, 0}] = 0;
    dp[{0, 1}] = 1;

    while (T--) {
        long long x, y;
        cin >> x >> y;
        cout << f(x, y) << '\n';
    }
}