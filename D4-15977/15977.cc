#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int M, N;
    cin >> M >> N;

    if (M == 2) {
        vector<pair<int, int> > v(N);
        for (int i = 0; i < N; ++i) cin >> v[i].first;
        for (int i = 0; i < N; ++i) cin >> v[i].second;
        sort(v.begin(), v.end());

        vector<int> dp;
        for (int i = 0; i < N; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), v[i].second);
            if (it == dp.end()) dp.push_back(v[i].second);
            else *it = v[i].second;
        }
        cout << dp.size() << '\n';
    } else {
        vector<tuple<int, int, int> > v(N);
        for (int i = 0; i < N; ++i) cin >> get<0>(v[i]);        
        for (int i = 0; i < N; ++i) cin >> get<1>(v[i]);        
        for (int i = 0; i < N; ++i) cin >> get<2>(v[i]);        
        sort(v.begin(), v.end());

        vector<set<pair<int, int> > > dp;

        for (int i = 0; i < N; ++i) {
            auto [ig, f, s] = v[i];
            pair<int, int> p = {f, s};
            auto it = lower_bound(dp.begin(), dp.end(), p, [&](auto& s_, auto& p_){
                auto it_ = s_.lower_bound(p_);
                if (it_ == s_.begin()) return false;
                --it_;
                return it_ -> second < p_.second;
            });

            if (it == dp.end()) {
                dp.push_back({{p}});
                continue;
            }

            auto it2 = it -> insert(p).first;
            ++it2;
            while (it2 != it -> end() && s < it2 -> second) {
                auto nit = next(it2);
                it -> erase(it2);
                it2 = nit;
            }
        }
        cout << dp.size() << '\n';
    }
}