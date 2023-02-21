#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<int>> vvi;
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

  int n,m;
  cin >> n >> m;
  vvi adj(n + 1, vi());
  while (m--) {
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  queue<int> q;
  q.push(1);
  vi visited(n + 1, 0);
  visited[1] = true;

  int dist = 0;
  vi ans;
  while (q.size()) {
    vi tmp;
    int cnt = q.size();
    while (cnt--) {
      auto f = q.front();
      q.pop();
      for (auto e: adj[f]) {
        if (visited[e]) continue;
        q.push(e);
        tmp.push_back(e);
        visited[e]= true;
      }
    }
    if (q.size()) {
      ans = tmp;
      ++dist;
    }
  }

  cout << *min_element(all(ans)) << ' ';
  cout << dist << ' ';
  cout << ans.size();
  
}