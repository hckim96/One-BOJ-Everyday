#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<int> parent;

int myFind(int n) {
    if (parent[n] == -1) {
        return n;
    }

    return parent[n] = myFind(parent[n]);
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    int tmp = (x1 * y2 + y1 * x3 + x2 * y3) - (x3 * y2 + x2 * y1 + x1 * y3);

    if (tmp > 0) {
        tmp = 1;
    }
    if (tmp < 0) {
        tmp = -1;
    }
    return tmp;
}

bool isIntersecting(tuple<int, int, int, int>& t1, tuple<int, int, int, int>& t2) {
    auto [x1, y1, x2, y2] = t1;
    auto [x3, y3, x4, y4] = t2;

    int ccw1 = ccw(x1, y1, x2, y2, x3, y3);
    int ccw2 = ccw(x1, y1, x2, y2, x4, y4);

    if (ccw1 == 0 && ccw2 == 0) {
        pair<int, int> p1 = {x1, y1};
        pair<int, int> p2 = {x2, y2};
        pair<int, int> p3 = {x3, y3};
        pair<int, int> p4 = {x4, y4};

        if (p1 > p2) {
            swap(p1, p2);
        }
        if (p3 > p4) {
            swap(p3, p4);
        }

        return p1 <= p4 && p3 <= p2;
    }

    int ccw3 = ccw(x3, y3, x4, y4, x1, y1);
    int ccw4 = ccw(x3, y3, x4, y4, x2, y2);
    
    return (ccw1 * ccw2 <= 0) && (ccw3 * ccw4 <= 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<tuple<int, int, int, int> > line(N);

    for (int i = 0; i < N; ++i) {
        auto & [x1, y1, x2, y2] = line[i];
        cin >> x1 >> y1 >> x2 >> y2;
    }

    vector<int> groupCnt(N, 1);
    parent.resize(N);
    fill(parent.begin(), parent.end(), -1);
    for (int i = 0; i < N; ++i) {
        int p1 = myFind(i);
        for (int j = i + 1; j < N; ++j) {
            int p2 = myFind(j);

            if (p1 == p2) {
                continue;
            }

            if (isIntersecting(line[i], line[j])) {
                parent[p2] = p1;
                groupCnt[p1] += groupCnt[p2];
            }
        }
    }

    int groupNum = 0;
    int groupCntMax = 1;
    for (int i = 0; i < N; ++i) {
        if (parent[i] == -1) {
            ++groupNum;
            groupCntMax = max(groupCntMax, groupCnt[i]);
        }
    }

    cout << groupNum << '\n';
    cout << groupCntMax << '\n';
}
