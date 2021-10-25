#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, n1, n2;
    cin >> N >> n1 >> n2;

    vector<vector<pair<int, int> > > adj(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < N - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    // n, sum, max
    queue<tuple<int, int, int> > q;
    q.push({n1, 0, 0});
    visited[n1] = true;
    while (!q.empty()) {
        auto [n, sum, max_] = q.front();
        q.pop();

        if (n == n2) {
            cout << sum - max_ << '\n';
            return 0;
        }

        for (auto [nn, nc]: adj[n]) {
            if (visited[nn]) continue;

            visited[nn] = true;
            q.push({nn, sum + nc, max(max_, nc)});
        }
    }
}