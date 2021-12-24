#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int k;
    while (cin >> k && k) {
        vector<int> a(k);
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
        }

        vector<int> answer(6);
        function<void(int, int)> f = [&](int cur, int cnt) {
            if (cnt == 6) {
                for (int i = 0; i < 6; ++i) {
                    cout << answer[i] << ' ';
                }
                cout << '\n';
                return;
            }

            if (cur >= k) return;

            answer[cnt] = a[cur];
            f(cur + 1, cnt + 1);
            f(cur + 1, cnt);
        };

        f(0, 0);
        cout << '\n';
    }
    
}
