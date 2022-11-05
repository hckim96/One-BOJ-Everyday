#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, R, Q;
  cin >> N >> R >> Q;

  vector<vector<int> > adj(N + 1);
  vector<int> ind(N + 1, 0);
  int tmp = N - 1;
  while (tmp--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int root = R;
  vector<int> ans(N + 1, 0);
  vector<int> visited(N + 1, 0);
  function<int(int)> f = [&](int v) {
    visited[v] = true;
    if (ans[v]) return ans[v];
    int tmp = 1;
    tmp = 1;
    for (auto e: adj[v]) {
      if (!visited[e])
      tmp += f(e);
    }
    return ans[v] = tmp;
  };

  f(root);
  while (Q--) {
    int v;
    cin >> v;
    cout << ans[v] << '\n';
  }
}