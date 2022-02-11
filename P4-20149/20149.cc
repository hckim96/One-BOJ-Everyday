#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<pair<long double, long double> > p(4);

    for (int i = 0; i < 4; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    auto f = [&](pair<long double, long double> p1, pair<long double, long double> p2, pair<long double, long double> p3, pair<long double, long double> p4) {
        if ((p2.second - p1.second) * (p4.first - p3.first) == (p4.second - p3.second) * (p2.first - p1.first)) {
            // same d
            if (p1 > p2) swap(p1, p2);
            if (p3 > p4) swap(p3, p4);

            if (p4 < p1 || p2 < p3) {
                cout << "0\n";
                return;
            }
            if (p1 == p4) {
                cout << "1\n";
                cout << p1.first << ' ' << p1.second << '\n';
                return;
            }
            if (p2 == p3) {
                cout << "1\n";
                cout << p2.first << ' ' << p2.second << '\n';
                return;
            }

            cout << "1\n";
        } else {
            // diff d
            cout << "1\n";
            if (p1.first == p2.first || p3.first == p4.first) {
                // d = inf
                if (p3.first == p4.first) {
                    swap(p1, p3);
                    swap(p2, p4);
                }

                long double a2 = (p4.second - p3.second) / (p4.first - p3.first);
                long double ay = a2 * (p1.first - p3.first) + p3.second;
                cout << p1.first << ' ' << ay << '\n';
            } else {
                long double a1 = (p2.second - p1.second) / (p2.first - p1.first);
                long double a2 = (p4.second - p3.second) / (p4.first - p3.first);
                long double ax = -(a2 * p3.first - p3.second - a1 * p1.first + p1.second) / (a1 - a2);
                long double ay = a1 * (ax - p1.first) + p1.second;
                cout << ax << ' ' << ay << '\n';
            }
        }
    };

    auto ccw = [&](pair<long double, long double> p1, pair<long double, long double> p2, pair<long double, long double> p3) {
        auto tmp = (p2.first - p1.first) * (p3.second - p2.second) - (p2.second - p1.second) * (p3.first - p2.first);
        if (tmp > 0) return 1;
        else if (tmp < 0) return -1;
        else return 0;
    };

    auto ccw1 = ccw(p[0], p[1], p[2]);
    auto ccw2 = ccw(p[0], p[1], p[3]);
    auto ccw3 = ccw(p[2], p[3], p[0]);
    auto ccw4 = ccw(p[2], p[3], p[1]);

    auto tmp1 = ccw1 * ccw2;
    auto tmp2 = ccw3 * ccw4;

    cout.precision(9);
    cout << fixed;
    if (tmp1 > 0 || tmp2 > 0) {
        cout << "0\n";
    } else {
        // tmp1 <= 0 && tmp2 <= 0
        f(p[0], p[1], p[2], p[3]);
    }
}