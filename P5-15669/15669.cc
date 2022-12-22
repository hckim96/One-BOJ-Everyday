#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  ll N, M;
  cin >> N >> M;

  vector<vector<int> > adj(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // 0 even, 1 odd
  vvl dp(N + 1, vl(2, 0));
  vl parent(N + 1, -1);

  function<void(int, int, int)> f = [&](int cur, int p, int parity) {
    dp[cur][parity] = 1;
    for (auto e: adj[cur]) {
      if (e == p) continue;
      parent[e] = cur;
      f(e, cur, !parity);
      dp[cur][parity] += dp[e][parity];
      dp[cur][!parity] += dp[e][!parity];
    }
  };
  f(1, -1, 0);

  while (M--) {
    ll u, v, c;
    cin >> u >> v >> c;
    if (parent[u] == v) swap(u, v);
    ll ans = 0;
    if (c) {
      // black,, changed,, 
      ans += dp[v][1] * (dp[1][0] - dp[v][0]);
      ans += dp[v][0] * (dp[1][1] - dp[v][1]);
    } else {
      ans += dp[v][1] * (dp[1][1] - dp[v][1]);
      ans += dp[v][0] * (dp[1][0] - dp[v][0]);
    }
    cout << ans << '\n';
  }
  
}