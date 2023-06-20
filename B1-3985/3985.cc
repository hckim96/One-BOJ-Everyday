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
typedef vector<string> vs;
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

  int l, n;
  cin >> l >> n;
  vi p(n),k(n);
  vi vis(l + 1, 0);
  vi ans(n);
  int ansIdx = 0;
  int ans2 = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> k[i];
    for (int j = p[i]; j <= k[i]; ++j) {
      if (vis[j]) continue;
      ans[i]++;
      vis[j] = true;
    }
    if (ans2 < k[i] - p[i] + 1) {
      ans2 = k[i] - p[i] + 1;
      ansIdx = i + 1;
    }
  }

  cout << ansIdx << '\n';
  cout << max_element(all(ans)) - ans.begin() + 1 << '\n';
}