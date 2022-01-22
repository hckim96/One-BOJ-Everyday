#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<int> v(N);
    for (auto& e: v) {
        cin >> e;
    }
    sort(all(v));

    vector<int> selected(M);
    function<void(int, int)> f = [&](int cur, int cnt) {
        if (cnt == M) {
            for (auto& e: selected) {
                cout << e << ' ';
            }
            cout << '\n';
            return;
        }
        if (cur == N) {
            return;
        }

        selected[cnt] = v[cur];
        f(cur + 1, cnt + 1);
        f(cur + 1, cnt);
    };

    f(0, 0);
}