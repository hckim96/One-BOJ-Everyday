#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pii;
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

  // x , h
  vector<pair<ll, ll> > v(n);
  each(e, v) cin >> e.first >> e.second;
  sort(all(v));

  // 오른쪽으로 i 넘어뜨렸을 때, 어디 인덱스 까지 넘어지냐
  vi r(n, -1);

  vi l(n, -1);

  vi tmp;
  
  ll cur = 0;
  for (int i = 0; i < n; ++i) {
    cur = 0;
    int j = i;
    while (true) {
      cur = max(cur, v[j].first + v[j].second);
      if (j == n - 1 || cur < v[j + 1].first) {
        r[i] = j;
        break;
      }
      ++j;
    }
  }

  for (int i = 0; i < n; ++i) {
    cur = 2e9;
    int j = i;
    while (true) {
      cur = min(cur, v[j].first - v[j].second);
      if (j == 0 || cur > v[j - 1].first) {
        l[i] = j;
        break;
      }
      --j;
    }
  }

  for (int i = 0; i < r.size(); ++i) {
    assert(r[i] >= i);
  }
  for (int i = 0; i < l.size(); ++i) {
    assert(l[i] <= i);
  }
  for (auto e: r) assert(e != -1);
  for (auto e: l) assert(e != -1);
  vi dp(n, 1e9);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    // i 왼쪽 넘어 뜨리기
    dp[i] = min(dp[i] , 1 + (l[i] ? dp[l[i] - 1] : 0));
    for (int j = 0; j < i; ++j) {
      // j ~ i 처리를 j 하나를 오른쪽으로 넘어뜨려기로 처리
      if (r[j] >= i) {
        dp[i] = min(dp[i], (j ? dp[j - 1] : 0) + 1);
      }
    }
  }
  for (auto e: dp) assert(e != 1e9);

  cout << dp[n - 1] << '\n';
}