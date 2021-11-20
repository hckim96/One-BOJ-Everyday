#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (auto& e: A) cin >> e;
    for (auto& e: B) cin >> e;

    vector<vector<int> > dp(N, vector<int> (N, -1));

    function<int(int, int)> f = [&](int a, int b) {
        if (a >= N || b >= N) return 0;

        auto& ret = dp[a][b];

        if (ret != -1) return ret;

        ret = max(ret, f(a + 1, b));
        ret = max(ret, f(a + 1, b + 1));
        if (A[a] > B[b]) ret = max(ret, f(a, b + 1) + B[b]);
        return ret;
    };

    cout << f(0, 0) << '\n';
}