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

struct cmp {
  bool operator()(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) return p1.second > p2.second;
    return p1.first > p2.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int n,m,k,x;
  cin >> n >> m >> k >> x;
  vvi adj(n + 1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
  }

  vi dist(n + 1, 1e9);
  dist[x] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int> >,  cmp> pq;
  pq.push({dist[x], x});
  while (pq.size()) {
    auto [td, tn] = pq.top();
    pq.pop();
    if (dist[tn] < td) continue;
    for (auto nn: adj[tn]) {
      if (dist[nn] > 1 + dist[tn]) {
        dist[nn] = 1 + dist[tn];
        pq.push({dist[nn], nn});
      }
    }
  }

  vi ans;

  for (int i = 1 ; i <= n; ++i) if (dist[i] == k) ans.push_back(i);

  if (ans.size()) {
    each(e, ans) cout << e << '\n';
  } else {
    cout << -1;
  }
}