#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int caseNum = 1;
    int N;

    auto cp = [&](pair<long double, long double> p1, pair<long double, long double> p2, pair<long double, long double> p3) {
        auto ret = (p2.first - p1.first) * (p3.second - p2.second) - (p2.second - p1.second) * (p3.first - p2.first);
        return ret;
    };
    
    pair<long double, long double> base;
    auto cmp = [&](pair<long double, long double> p1, pair<long double, long double> p2) {
        auto cp_ = cp(base, p1, p2);
        if (cp_ != 0) {
            return cp_ > 0;
        }
        return (base.first - p1.first) * (base.first - p1.first) + (base.second - p1.second) * (base.second - p1.second) < (base.first - p2.first) * (base.first - p2.first) + (base.second - p2.second) * (base.second - p2.second);
    };

    while (cin >> N && N) {

        vector<pair<long double, long double> > p(N);
        for (int i = 0; i < N; ++i) {
            cin >> p[i].first >> p[i].second;
        }

        swap(p[0], *min_element(all(p)));

        base = p[0];

        sort(all(p), cmp);

        stack<pair<long double, long double> > st;
        st.push(p[0]);
        st.push(p[1]);
        for (int i = 2; i < N; ++i) {
            auto p2 = st.top(); st.pop();
            auto p1 = st.top();
            auto p3 = p[i];

            auto cp_ = cp(p1, p2, p3);
            while (cp_ < 0) {
                p2 = p1;
                st.pop(); p1 = st.top();
                cp_ = cp(p1, p2, p3);
            }

            if (cp_ > 0) {
                st.push(p2);
                st.push(p3);
            } else {
                //  cp_ = 0
                st.push(p3);
            }
        }

        vector<pair<long double, long double> > convexHull(st.size());
        while (st.size()) {
            convexHull[st.size() - 1] = st.top();
            st.pop();
        }

        long double answer = 1e18;
        
        for (int i = 0; i < convexHull.size(); ++i) {
            auto p1 = convexHull[i];
            auto p2 = convexHull[(i + 1) % (convexHull.size())];
            long double maxDist = 0;
            long double p1p2 = sqrtl((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
            for (int j = 0; j < convexHull.size(); ++j) {
                auto p3 = convexHull[j];
                auto cp_ = abs(cp(p1, p2, p3));
                maxDist = max(maxDist, cp_ / p1p2);
            }
            answer = min(answer, maxDist);
        }

        answer *= 100;
        if (answer - (long long)answer > 1e-12) {
            answer += 1;
            answer = (long long)answer;
        }
        answer /= 100;
        cout.precision(2);
        cout << fixed;
        cout << "Case " << caseNum++ << ": " << answer << '\n';
    }
}