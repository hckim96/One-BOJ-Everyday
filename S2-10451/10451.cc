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

        vector<int> v(N + 1, 0);

        for (int i = 1; i <= N; ++i) {
            cin >> v[i];
        }
        
        vector<int> visited(N + 1, false);
        int answer = 0;

        int seq = 1;
        function<void(int)> f = [&](int cur) {
            if (visited[cur]) return;
            visited[cur] = seq;
            f(v[cur]);
        };

        for (int i = 1; i <= N; ++i) {
            if (visited[i]) continue;
            ++seq;
            f(i);
        }
        cout << seq - 1 << '\n';
    }
}