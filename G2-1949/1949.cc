#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N;
  cin >> N;

  vector<int> v(N + 1, 0);
  vector<int> p(N + 1, -1);
  for (int i = 1; i <= N; ++i) {
    cin >> v[i];
  }

  vector<vector<int> > adj(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  while (q.size()) {
    auto f = q.front();
    q.pop();
    for (auto e: adj[f]) {
      if (e == p[f]) continue;
      q.push(e);
      p[e] = f;
    }
  }
  // n, good?, pgood?
  vector<vector<vector<int> > > dp(N + 1, vector<vector<int> > (2, vector<int> (2, -1)));

  function<int(int, int, int)> f = [&](int n, int g, int pg) {
    if (dp[n][g][pg] != -1) return dp[n][g][pg];
    int ret = 0;
    if (g) {
      int tmp = v[n];
      for (auto e: adj[n]) {
        if (e == p[n]) continue;
        tmp += f(e, 0, 1);
      }
      ret = max(ret, tmp);
    } else {
      if (pg) {
        int tmp = 0;
        for (auto e: adj[n]) {
          if (e == p[n]) continue;
          tmp += max(f(e, 0, 0), f(e, 1, 0));
        }
        ret = max(ret, tmp);
      } else {
        for (int i = 0; i < adj[n].size(); ++i) {
          if (adj[n][i] == p[n]) continue;
          int tmp = f(adj[n][i], 1, 0);
          for (int j = 0; j < adj[n].size(); ++j) {
            if (adj[n][j] == p[n]) continue;
            if (i == j) continue;
            tmp += max(f(adj[n][j], 0, 0), f(adj[n][j], 1, 0));
          }
          ret = max(ret, tmp);
        }
      }
    }
    return dp[n][g][pg] = ret;
  };
  cout << max(f(1, 0, 0), f(1, 1, 0));
}