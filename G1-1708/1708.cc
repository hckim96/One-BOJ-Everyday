#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>

using namespace std;

pair<int, int> start = {40000, 40000};

int ccw(pair<int, int>& p1, pair<int, int>& p2, pair<int, int>& p3) {
    long long tmp = 1LL * p1.first * p2.second + p3.first * p1.second + p2.first * p3.second - (1LL * p3.first * p2.second + p1.first * p3.second + p2.first * p1.second);

    if (tmp > 0) {
        return 1;
    }

    if (tmp < 0) {
        return -1;
    }

    return 0;
}

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    int ccw_ = ccw(start, p1, p2);

    if (ccw_ == 0) {
        return abs(start.first - p1.first) + abs(start.second - p1.second) < abs(start.first - p2.first) + abs(start.second - p2.second);
    }

    return ccw_ > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int> > point(N);

    for (int i = 0; i < N; ++i) {
        cin >> point[i].first >> point[i].second;
        if (point[i].second < start.second) {
            start = point[i];
        } else if (point[i].second == start.second) {
            if (point[i].first < start.first) {
                start = point[i];
            }
        }
    }

    // sort by angle
    sort(point.begin(), point.end(), cmp);

    stack<pair<int, int> > st;
    st.push(point[0]);
    st.push(point[1]);

    for (int i = 2; i < N; ++i) {
        auto p2 = st.top();
        st.pop();
        auto p1 = st.top();

        auto p3 = point[i];

        int ccw_ = ccw(p1, p2, p3);

        while (ccw_ < 0) {
            p2 = p1;
            st.pop();
            p1 = st.top();

            ccw_ = ccw(p1, p2, p3);
        }

        if (ccw_ > 0) {
            st.push(p2);
            st.push(p3);
        } else if (ccw_ == 0) {
            st.push(p3);
        }

    }

    cout << st.size() << '\n';
}
