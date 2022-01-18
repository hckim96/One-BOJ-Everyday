#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int TC; cin >> TC;
    while (TC--) {
        int N;
        cin >> N;

        vector<pair<int, int> > v(N);
        for (auto& e: v) {
            cin >> e.first >> e.second;
        }
        sort(all(v));

        int answer = 0;
        int y = 1e9;
        for (auto& e: v) {
            if (e.second >= y) {
                continue;
            }

            y = e.second;
            ++answer;
        }
        cout << answer << '\n';
    } 
}