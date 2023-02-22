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

  int s1, s2, s3;
  cin >> s1 >> s2 >> s3;

  int maxCnt = 0;
  int ans = 0;
  map<int, int> m;
  for (int i = 1; i <= s1; ++i) {
    for (int j = 1; j <= s2; ++j) {
      for (int k = 1; k <= s3; ++k) {
        if (maxCnt < ++m[i+j+k]) {
          maxCnt = m[i + j+ k];
          ans = i + j + k;
        }
      }
    }
  }

  cout << ans;
}