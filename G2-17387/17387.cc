#include <iostream>
#include <vector>

using namespace std;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3) {
    long long tmp = (p2.first - p1.first) * (p2.second - p3.second) - (p2.first - p3.first) * (p2.second - p1.second);

    if (tmp > 0) {
        return 1;
    } else if (tmp == 0) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    vector<pair<long long, long long> > p(5);

    for (int i = 1; i <= 4; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    if (ccw(p[1], p[2], p[3]) == 0 && ccw(p[1], p[2], p[4]) == 0) {
        if (p[1] > p[2]) {
            swap(p[1], p[2]);
        }
        if (p[3] > p[4]) {
            swap(p[3], p[4]);
        }

        cout << ((p[1] <= p[4]) && (p[2] >= p[3])) << '\n';
        return 0;
    }
    cout << ((ccw(p[3], p[4], p[1]) * ccw(p[3], p[4], p[2]) <= 0) && (ccw(p[1], p[2], p[3]) * ccw(p[1], p[2], p[4]) <= 0)) << '\n';
}
