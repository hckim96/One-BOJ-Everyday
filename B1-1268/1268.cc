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
  vvi v(n, vi(5, 0));
  each(e, v) each(ee, e) cin >> ee;

  vector<set<int> > cnt(n);

  for (int j = 0; j < 5; ++j) {
    for (int i = 0; i < n; ++i) {
      for (int k = i + 1; k < n; ++k) {
        if (v[i][j] == v[k][j]) {
          cnt[i].insert(k);
          cnt[k].insert(i);
        }
      }
    }
  }

  int max_ = 0;
  int ans = 1;

  for (int i = 0; i < cnt.size(); ++i) {
    if (max_ < cnt[i].size()) {
      ans = i + 1;
      max_ = cnt[i].size();
    }
  }
  cout << ans;
}