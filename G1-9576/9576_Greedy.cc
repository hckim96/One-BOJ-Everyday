#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M;
        cin >> N >> M;
        
        vector<pair<int, int> > v(M);

        for (auto& [a, b]: v) {
            cin >> a >> b;
        }

        sort(v.begin(), v.end(), cmp);

        vector<bool> left(N + 1, true);

        int answer = 0;
        for (auto [a, b]: v) {
            for (int i = a; i <= b; ++i) {
                if (left[i]) {
                    left[i] = false;
                    ++answer;
                    break;
                }
            }
        }
        cout << answer << '\n';
    }
}