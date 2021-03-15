#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void f(vector<vector<int> >& edge, vector<vector<int> >& dp, vector<bool>& visited, int root) {
    if (dp[root][false] != -1) {
        return;
    }

    dp[root][false] = 0;
    dp[root][true] = 1;
    for (auto v: edge[root]) {

        if (visited[v]) {
            continue;
        }

        visited[v] = true;
        f(edge, dp, visited, v);
        dp[root][false] += dp[v][true];
        dp[root][true] += min(dp[v][false], dp[v][true]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int> > edge(N + 1, vector<int> ());

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vector<bool> visited(N + 1, false);
    vector<vector<int> > dp(N + 1, vector<int> (2, -1));
    visited[1] = true;
    f(edge, dp, visited, 1);

    cout << min(dp[1][false], dp[1][true]) << '\n';
}