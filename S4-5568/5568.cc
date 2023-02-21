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

  int n,k;
  cin >> n >> k;
  vi v(n);
  vi visited(n);
  each(e, v) cin >> e;

  set<string> ans;

  function<void(vi&, int)> f = [&](vector<int>& vv, int cnt) {
    if (cnt == k) {
      string tmp = "";
      each(e, vv) tmp += to_string(e);
      ans.insert(tmp);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (visited[i]) continue;
      visited[i] = true;
      vv.push_back(v[i]);
      f(vv, cnt + 1);
      vv.pop_back();
      visited[i] = false;
    }
  };

  vi tmp;
  f(tmp, 0);
  cout << ans.size();
}