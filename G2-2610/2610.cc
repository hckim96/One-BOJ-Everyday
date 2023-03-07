#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int n, m;
  cin >> n >> m;
  vvi adj(n + 1);
  vvi dist(n + 1, vi(n + 1, 1e9));
  for (int i = 1; i <= n; ++i) dist[i][i] = 0;

  rep(m) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    dist[a][b] = dist[b][a] = 1;
  }
  
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= n; ++i) {
      for (int k = 1; k <= n; ++k) {
        if (dist[i][k] > dist[i][j] + dist[j][k]) {
          dist[i][k] = dist[i][j] + dist[j][k];
        }
      }
    }
  }
  // each(e, dist) {
  //   each(ee, e) {
  //     cout << (ee == 1e9 ? 0 : ee) << ' ';
  //   }
  //   cout << '\n';
  // }

  vi maxd(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (dist[i][j] != 1e9)
      maxd[i] = max(maxd[i], dist[i][j]);
    }
  }

  queue<int> q;
  vi vis(n + 1, 0);
  vi ans;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;

    vis[i] = true;
    q.push(i);
    int tmp = i;
    int tmp2 = 1e9;
    while (q.size()) {
      auto f = q.front();
      q.pop();
      if (maxd[f] < tmp2) {
        tmp = f;
        tmp2 = maxd[f];
      }
      for (auto e: adj[f]) {
        if (vis[e]) continue;
        vis[e] = true;
        q.push(e);
      }
    }
    ans.push_back(tmp);
  }
  cout << ans.size() << '\n';
  sort(all(ans));
  each(e, ans) cout << e << '\n';
}