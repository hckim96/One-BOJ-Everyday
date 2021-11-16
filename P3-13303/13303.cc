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

    int sY, eX;
    cin >> sY >> eX;

    vector<tuple<int, int, int> > v(N);
    for (int i = 0; i < N; ++i) {
        int x, l, h;
        cin >> x >> l >> h;
        v[i] = {x, l, h};
    }

    sort(all(v));
    // y, movedY;
    set<pair<int, long long> > s;
    s.insert({sY, 0});

    for (int i = 0; i < N; ++i) {
        auto [x, l, h] = v[i];

        auto it = s.lower_bound({l, -1});
        
        long long minToL = 1e18;
        long long minToH = 1e18;

        while (it != s.end() && it -> first < h) {
            minToH = min(minToH, it -> second + h - it -> first);
            minToL = min(minToL, it -> second + it -> first - l);
            it = s.erase(it);
        }
        if (minToL != 1e18) {
            s.insert({l, minToL});
            s.insert({h, minToH});
        }
    }

    set<int> answerY;
    long long minMoved = 1e18;

    for (auto [yy, movedY]: s) {
        if (minMoved > movedY) {
            minMoved = movedY;
            answerY.clear();
            answerY.insert(yy);
        } else if (minMoved == movedY) {
            answerY.insert(yy);
        }
    }
    
    cout << minMoved + eX << '\n';
    cout << answerY.size() << ' ';
    for (auto e: answerY) {
        cout << e << ' ';
    }
    cout << '\n';
}