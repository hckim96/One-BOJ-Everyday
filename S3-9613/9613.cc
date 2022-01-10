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

        vector<int> v(N);
        for (auto& e: v) {
            cin >> e;
        }

        long long answer = 0;

        vector<int> selectedNum(N);

        function<void(int, int)> f = [&](int cur, int selected) {
            if (selected == 2) {
                int gcd_ = selectedNum[0];
                for (int i = 1; i < selected; ++i) {
                    gcd_ = gcd(gcd_, selectedNum[i]);
                }
                answer += gcd_;
                return;
            }
            if (cur == N) {
                return;
            }

            f(cur + 1, selected);
            selectedNum[selected] = v[cur];
            ++selected;
            f(cur + 1, selected);
        };

        f(0, 0);
        cout << answer << '\n';
    }
}