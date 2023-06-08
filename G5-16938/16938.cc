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

  int n, l, r, x;
  cin >> n >> l >> r >> x;

  vi a(n);
  each (e, a) cin >> e;

  int ans = 0;
  function<void(int, vi&)> f = [&](int cur, vi& tmp) {
    if (cur == n) {
      if (tmp.size() == 0) return;
      int sum = accumulate(all(tmp),0);
      if (sum < l) return;
      if (sum > r) return;
      if (*max_element(all(tmp)) - *min_element(all(tmp)) < x) return;
      ++ans;
      return;
    }

    f(cur + 1, tmp);
    tmp.push_back(a[cur]);
    f(cur + 1, tmp);
    tmp.pop_back();
  };

  vi tmp;
  f(0, tmp);
  cout << ans;
}