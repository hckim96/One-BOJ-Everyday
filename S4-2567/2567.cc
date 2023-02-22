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

  vvi v(100, vi(100, 0));

  int TC; cin >> TC;
  while (TC--) {
    int r, c;
    cin >> r >> c;
    for (int i = r; i < r + 10; ++i) {
      for (int j = c; j < c + 10; ++j) {
        v[i][j] = 1;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0 ; j< 100; ++j) {
      if (v[i][j] == 0) continue;

      for (int dir = 0; dir < 4; ++dir) {
        int ni = i + dr[dir];
        int nj = j + dc[dir];
        if (ni < 0 || ni >= 100 || nj < 0 || nj >= 100 || v[ni][nj] == 0) {
          ++ans;
        }
      }
    }
  }
  cout << ans;
}