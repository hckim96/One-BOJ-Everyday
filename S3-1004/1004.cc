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
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int N;
        cin >> N;

        set<int> all, both;
        while (N--) {
            int cx, cy, r;
            cin >> cx >> cy >> r;

            auto isIn = [&](int cx, int cy, int r, int x, int y) {
                return (cx - x) * (cx - x) + (cy - y) * (cy - y) <= r * r;
            };

            if (isIn(cx, cy, r, x1, y1) || isIn(cx, cy, r, x2, y2)) {
                all.insert(N);
            }
            if (isIn(cx, cy, r, x1, y1) && isIn(cx, cy, r, x2, y2)) {
                both.insert(N);
            }
        }
        cout << all.size() - both.size() << '\n';
    }
}