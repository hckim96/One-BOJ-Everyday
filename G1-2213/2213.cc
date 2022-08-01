#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N;
  cin >> N;
  vector<int> w(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> w[i];
  }

  vector<vector<int> > adj(N + 1);
  for (int i = 0; i < N - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  function<pair<ll, vector<int> >(int, int, int)> f = [&](int parent, int cur, int select) {
    pair<ll, vector<int> > ret;
    ret.first = 0;
    if (select) ret.first += w[cur], ret.second.push_back(cur);
    for (auto e: adj[cur]) {
      if (e == parent) continue;
      if (select) {
        auto tmp = f(cur, e, !select);
        ret.first += tmp.first;
        for (auto e: tmp.second) ret.second.push_back(e);
      } else {
        auto tmp1 = f(cur, e, !select);
        auto tmp2 = f(cur, e, select);
        if (tmp1.first > tmp2.first) {
          ret.first += tmp1.first;
          for (auto e: tmp1.second) ret.second.push_back(e);
        } else {
          ret.first += tmp2.first;
          for (auto e: tmp2.second) ret.second.push_back(e);
        }
      }
    }
    return ret;
  };
  auto tmp1 = f(0, 1, !0);
  auto tmp2 = f(0, 1, 0);
  if (tmp1.first > tmp2.first) {
    cout << tmp1.first << '\n';
    sort(all(tmp1.second));
    for (auto e: tmp1.second) cout << e << ' ';
    cout << '\n';
  } else {
    cout << tmp2.first << '\n';
    sort(all(tmp2.second));
    for (auto e: tmp2.second) cout << e << ' ';
    cout << '\n';
  }
}
