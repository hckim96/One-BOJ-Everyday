#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int TC; cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        
        tuple<long long, long long, long long> base;
        vector<tuple<long long, long long, long long> > v(N);
        for (int i = 0; i < N; ++i) {
            auto& [a, b, c] = v[i];
            cin >> a >> b;
            c = i;
        }

        auto ccw = [&](tuple<long long, long long, long long> t1, tuple<long long, long long, long long> t2, tuple<long long, long long, long long> t3) {
            auto [x1, y1, i1] = t1;
            auto [x2, y2, i2] = t2;
            auto [x3, y3, i3] = t3;
            auto tmp = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
            if (tmp < 0) return -1;
            else if (tmp > 0) return 1;
            else return 0;
        };
        
        auto cmp = [&](tuple<long long, long long, long long> t1, tuple<long long, long long, long long> t2) {
            auto tmp = ccw(base, t1, t2);
            if (tmp < 0) {
                return false;
            } else if (tmp > 0) {
                return true;
            } else {
                auto [x0, y0, i0] = base;
                auto [x1, y1, i1] = t1;
                auto [x2, y2, i2] = t2;
                return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1) < (x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2);
            }
        };

        base = *min_element(all(v));
        sort(all(v), cmp);
        for (int i = v.size() - 1; i > 0; --i) {
            if (ccw(base, v[i], v[i - 1])) {
                reverse(v.begin() + i, v.end());
                break;
            }
        }
        for (auto [a, b, c]: v) {
            cout << c << ' ';
        }
        cout << '\n';
    }
}