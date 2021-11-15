#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<pair<int, int> > A(N), B(M);

    for (auto& e: A) cin >> e.first >> e.second;
    for (auto& e: B) cin >> e.first >> e.second;

    auto ccw = [&](pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3) {
        return 1LL * (p2.first - p1.first) * (p3.second - p2.second) - 1LL * (p2.second - p1.second) * (p3.first - p2.first) >= 0;
    };

    auto in = [&](vector<pair<int, int> >& v, pair<int, int>& p) {
        int N = v.size();
        int lo = 0;
        int hi = N;
        while (lo + 1 < hi) {
            int mid = lo + hi >> 1;
            if (ccw(v[0], v[mid], p)) lo = mid;
            else hi = mid;
        }

        if (lo == 0 || lo == N - 1) return false;
        return ccw(v[lo], v[lo + 1], p);
    };

    int answer = 0;
    while (K--) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        if (!(in(A, p) && !in(B, p))) ++answer;
    }
    if (answer) {
        cout << answer << '\n';
    } else {
        cout << "YES\n";
    }
}