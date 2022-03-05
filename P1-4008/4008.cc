#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
struct line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
    long double intersectX(line l) { return (long double) (c - l.c) / (l.m - m); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int N;
    cin >> N;
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> v(N + 1, 0), pv(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        pv[i] = v[i] + pv[i - 1];
    }

    deque<line> dq;
    dq.push_front({0, 0});
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        while (dq.size() >= 2 && dq[0].eval(pv[i]) <= dq[1].eval(pv[i]))
            dq.pop_front();

        ans = dq.front().eval(pv[i]);

        line cur = {-2LL * a * pv[i], a * pv[i] * pv[i] - b * pv[i] + ans +a * pv[i] * pv[i] + b * pv[i] + c };
        while (dq.size() >= 2 && cur.intersectX(dq.back()) <= dq.back().intersectX(dq[dq.size() - 2]))
            dq.pop_back();
        dq.push_back(cur);
    }

    cout << ans + a * pv[N] * pv[N] + b * pv[N] + c << '\n';
}