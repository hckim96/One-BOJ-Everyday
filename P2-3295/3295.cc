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
        int N, M;
        cin >> N >> M;

        vector<vector<int> > adj(N);
        vector<int> B(N, -1);

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector<int> visited(N, 0);
        function<bool(int)> f = [&](int a) {
            visited[a] = true;
            for (auto b: adj[a]) {
                if (B[b] == -1 || (!visited[B[b]] && f(B[b]))) {
                    B[b] = a;
                    return true;
                }
            }
            return false;
        };

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            fill(all(visited), false);
            ans += f(i);
        }
        cout << ans << '\n';
    }
}