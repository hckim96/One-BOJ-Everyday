#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    auto ccw = [&](pair<long long , long long >& p1, pair<long long , long long >& p2, pair<long long , long long >& p3) {
        return (p2.first - p1.first) * (p3.second - p2.second) - (p2.second - p1.second) * (p3.first - p2.first);
    };
    auto distSqr = [&](pair<long long , long long >& p1, pair<long long , long long >& p2) {
        return (p2.first - p1.first) * (p2.first - p1.first) + (p2.second - p1.second) * (p2.second - p1.second);
    };
    auto buildConvexHull = [&](vector<pair<long long , long long > >& p) {

        swap(p[0], *min_element(all(p)));
        auto base = p[0];

        auto cmp = [&](pair<long long , long long >& p1, pair<long long , long long >& p2) {
            auto ccw_ = ccw(base, p1, p2);
            if (ccw_ == 0) {
                return distSqr(base, p1) < distSqr(base, p2); 
            }
            return ccw_ > 0;
        };
        sort(all(p), cmp);
        stack<pair<long long , long long > > st;
        st.push(p[0]);
        st.push(p[1]);
        for (int i = 2; i < p.size(); ++i) {
            auto p2 = st.top(); st.pop();
            auto p1 = st.top();
            auto p3 = p[i];
            auto ccw_ = ccw(p1, p2, p3);
            while (ccw_ < 0) {
                p2 = p1;
                st.pop(); p1 = st.top();
                ccw_ = ccw(p1, p2, p3);
            }

            if (ccw_ > 0) {
                st.push(p2);
                st.push(p3);
            } else {
                st.push(p3);
            }
        }
        vector<pair<long long , long long > > convexHull(st.size());
        while (st.size()) {
            convexHull[st.size() - 1] = st.top();
            st.pop();
        }

        return convexHull;
    };

    int TC; cin >> TC;
    while (TC--) {
        int N;
        cin >> N;

        vector<pair<long long, long long> > v(N);
        for (auto& e: v) {
            cin >> e.first >> e.second;
        }

        auto ch = buildConvexHull(v);
        auto pl = min_element(all(ch)) - ch.begin();
        auto pr = max_element(all(ch)) - ch.begin();

        pair<int, int> answer = {pl, pr};
        long long tmp = distSqr(ch[pl], ch[pr]);
        int chSize = ch.size();
        for (int i = 0; i < chSize; ++i) {
            pair<long long, long long> v1 = {ch[(pl + 1) % chSize].first - ch[pl].first, ch[(pl + 1) % chSize].second - ch[pl].second};
            pair<long long, long long> v2 = {ch[pr].first - ch[(pr + 1) % chSize].first, ch[pr].second - ch[(pr + 1) % chSize].second};
            if (v1.first * v2.second - v1.second * v2.first > 0) {
                pl = (pl + 1) % chSize;
            } else {
                pr = (pr + 1) % chSize;
            }

            if (tmp < distSqr(ch[pl], ch[pr])) {
                tmp = distSqr(ch[pl], ch[pr]);
                answer = {pl, pr};
            }
        }

        cout << ch[answer.first].first << ' ' << ch[answer.first].second << ' ';
        cout << ch[answer.second].first << ' ' << ch[answer.second].second << '\n';
    }
}