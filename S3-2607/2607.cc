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

  int n;
  cin >> n;
  vector<string> v(n);
  vector<vector<int> > vv(n, vector<int> (26, 0));

  for (int i = 0; i < n; ++i){
    cin >> v[i];
    each(ee, v[i]) {
      vv[i][ee - 'A']++;
    }
  }

  int ans = 0;

  auto same = [&](vi& v1, vi& v2) {
    for (int i = 0; i <v1.size(); ++i) {
      if (v1[i] != v2[i]) return false;
    }
    return true;
  };
  auto similar = [&](int cur) {
    auto f = vv[0];
    auto m = vv[cur];

    if (same(f, m)) return true;

    for (int i = 0; i < f.size(); ++i) {
      f[i]++;
      if (same(f, m)) return true;
      f[i] -= 2;
      if (same(f, m)) return true;
      f[i]++;

      for (int j = 0; j < f.size(); ++j) {
        if (i == j) continue;

        f[i]--;
        f[j]++;
        if (same(f, m)) return true;
        f[i]++;
        f[j]--;
      }
    }
    return false;
  };

  for (int i = 1; i < v.size(); ++i) {
    if (similar(i)) ans++;
  }
  cout << ans;
}