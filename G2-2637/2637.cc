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
  vector<vector<pair<int, int> > > adj(n + 1);

  rep(m) {
    int x, y, z;
    cin >> x >> y >> z;
    adj[x].push_back({y, z});
  }

  map<int, int> mp;
  
  // queue<pair<int, int> > q;
  // q.push({n, 1});
  // while (q.size()) {
  //   auto [fn, fcnt] = q.front();
  //   q.pop();
  //   if (adj[fn].size() == 0) {
  //     mp[fn] += fcnt;
  //     continue;
  //   }

  //   for (auto [nn, ncnt]: adj[fn]) {
  //     q.push({nn, ncnt * fcnt});
  //   }
  // }

  // function<void(int, int)> f = [&](int cur, int cnt) {
  //   if (adj[cur].size() == 0) {
  //     mp[cur] += cnt;
  //     return;
  //   }

  //   for (auto [nn, ncnt]: adj[cur]) {
  //     if (adj[nn].size() == 0) {
  //       mp[nn] += cnt * ncnt;
  //       continue;
  //     }
  //     f(nn, cnt * ncnt);
  //   }
  // };
  // f(n, 1);

  mp[n] = 1;


  while (true) {
    int changed = false;

    for (auto [k, v]: mp) {
      if (v == 0) {
        continue;
      }

      if (adj[k].size() != 0) {
        changed = true;
        for (auto [nn, ncnt]: adj[k]) {
          mp[nn] += ncnt * mp[k];
        }
        mp[k] = 0;
      }
    }

    if (!changed) break;
  }

  for (auto [k, v]: mp) {
    if (v == 0) continue;
    cout << k << ' ' << v << '\n';
  }
}