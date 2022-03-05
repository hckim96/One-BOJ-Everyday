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
    vector<long long> a(N), b(N);
    for (auto& e: a) {
        cin >> e;
    }
    for (auto& e: b) {
        cin >> e;
    }

    deque<line> dq;
    long long ans = 0;
    dq.push_front({b[0], 0});
    for (int i = 1; i < N; i++) {
        while (dq.size() >= 2 && dq[0].eval(a[i]) >= dq[1].eval(a[i]))
            dq.pop_front();
        ans = dq.front().eval(a[i]);
        line cur = {b[i], ans};
        while (dq.size() >= 2 && cur.intersectX(dq.back()) <= dq.back().intersectX(dq[dq.size() - 2]))
            dq.pop_back();
        dq.push_back(cur);
    }
    cout << ans << '\n';
}