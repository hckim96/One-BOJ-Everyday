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

    vector<pair<int, int> > v(N);

    for (auto& e: v) cin >> e.first >> e.second;

    sort(all(v), [&](pair<int, int>& p1, pair<int, int>& p2){
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    });

    int cnt = 0;

    for (int i = 5; i < v.size(); ++i) {
        if (v[i].first != v[4].first) {
            break;
        }
        ++cnt;
    }
    cout << cnt << '\n';
}