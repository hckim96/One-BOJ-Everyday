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

  vvi v(20, vi(20));
  for (int i = 1; i <= 19; ++i) {
    for (int j = 1; j <= 19; ++j) {
      cin >> v[i][j];
    }
  }

  int ans = 0;
  int ansr, ansc;

  auto check = [&](int r, int c, int t) {

    int dr[4] = {1, 1, 0, -1};
    int dc[4] = {0, 1, 1, 1};

    for (int dir = 0; dir < 4; ++dir) {
      int yes = true;
      for (int vv = 1; vv <= 4; ++vv) {
        int rr = r + dr[dir] * vv;
        int cc = c + dc[dir] * vv;
        if (rr < 1 || rr > 19 || cc < 1 || cc > 19 || v[rr][cc] != t) {
          yes = false;
          break;
        }
      }
      if (yes) {
        int rr = r + dr[dir] * 5;
        int cc = c + dc[dir] * 5;
        int rrr = r - dr[dir];
        int ccc = c - dc[dir];
        if (rr >= 1 && rr <= 19 && cc >= 1 && cc <= 19 && v[rr][cc] == t) continue;
        if (rrr >= 1 && rrr <= 19 && ccc >= 1 && ccc <= 19 && v[rrr][ccc] == t) continue;
        return true;
      }
    }
    return false;
  };

  for (int j = 1; j <= 19; ++j) {
    for (int i = 1; i <= 19; ++i) {
      if (v[i][j] == 0) continue;

      if (check(i, j, v[i][j])) {
        if (ans == 0) {
          ans = v[i][j];
          ansr = i;
          ansc = j;
        } else if (ans <= 2) {
          if (ans != v[i][j]) {
            ans += v[i][j];
          }
        }
      }
    }
  }

  if (ans == 1 || ans == 2) {
    cout << ans << '\n';
    cout << ansr << ' ' << ansc;
  } else {
    cout << 0;
  }
}