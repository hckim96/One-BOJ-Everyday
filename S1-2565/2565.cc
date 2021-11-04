#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    vector<pair<int, int> > v(N);
    for (auto& e: v) {
        cin >> e.first >> e.second;
    }    
    sort(v.begin(), v.end());

    vector<int> dp;
    for (auto [ig, val]: v) {
        auto it = lower_bound(dp.begin(), dp.end(), val);
        if (it == dp.end()) dp.push_back(val);
        else *it = val;
    }
    cout << N - dp.size() << '\n';
}