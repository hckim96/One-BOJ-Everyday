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

string max_(string& s1, string& s2) {
  if (s1.length() > s2.length()) return s1;
  if (s1.length() < s2.length()) return s2;

  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] > s2[i]) return s1;
    if (s1[i] < s2[i]) return s2;
  }

  return s1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int n;
  cin >> n;
  vi p(n);
  each(e, p) cin >> e;
  int m; 
  cin >> m;
  vector<string> dp(m + 1, "");

  for (int i = 0; i < dp.size(); ++i) {
    for (int j = 0; j <= i; ++j) {
      dp[i] = max_(dp[i], dp[j]);
      for (int k = 0; k < p.size(); ++k) {
        if (p[k] <= i - j) {
          string tmp = dp[j] + to_string(k);
          if (tmp.size() > 1 && tmp[0] == '0') tmp = tmp.substr(1);
          dp[i] = max_(dp[i], tmp);
        }
      }
    }
  }
  cout << dp[m];
}