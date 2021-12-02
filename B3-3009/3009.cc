#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<pair<int, int> > v(3);
    for (int i = 0; i < 3; ++i) {
        cin >> v[i].first >> v[i].second;
    }

    pair<int, int> answer;
    for (int i = 1; i < 3; ++i) {
        if (v[0].first != v[i].first && v[0].second != v[i].second) {
            answer = {v[0].first + v[i].first - v[3 - i].first, v[0].second + v[i].second - v[3 - i].second};
        }
    }
    if (answer.first == 0 && answer.second == 0) {
        answer = {v[1].first + v[2].first - v[0].first, v[1].second + v[2].second - v[0].second};
    }
    cout << answer.first << ' ' << answer.second << '\n';
}