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

    vector<pair<int, int> > answer;
    function<void(int, int, int)> f = [&](int cnt, int s, int e) {
        if (cnt == 1) {
            answer.push_back({s, e});
            return;
        }

        f(cnt - 1, s, 6 - s - e);
        answer.push_back({s, e});
        f(cnt - 1,6 - s - e, e);
    };

    f(N, 1, 3);
    cout << answer.size() << '\n';
    for (auto e: answer) {
        cout << e.first << ' ' << e.second << '\n';
    }
}