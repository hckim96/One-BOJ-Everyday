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


  int R, C, K;
  cin >> R >> C >> K;

  vector<string> v(R);
  each(e, v) cin >> e;

  int ans = 0;
  vvi vis(R, vi(C, 0));
  function<void(int ,int ,int)> f = [&](int r, int c, int cnt) {
    if (r == 0 && c == C - 1) {
      if (cnt == K) {
        ++ans;
      }
      return;
    }

    for (int dir = 0; dir < 4; ++dir) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (vis[nr][nc]) continue;
      if (v[nr][nc] == 'T') continue;
      vis[nr][nc] = true;
      f(nr, nc, cnt + 1);
      vis[nr][nc] = false;
    }
  };
  vis[R - 1][0] = true;
  f(R - 1, 0, 1);
  cout << ans;
}