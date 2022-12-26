#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  ll N, M;
  cin >> N >> M;

  vvl v(N, vl(M));
  for (auto& e: v) for (auto& ee: e) cin >> ee;

  vvl visited(N, vl(M, 0));
  function<bool(int, int)> f = [&](int r, int c) {
    visited[r][c] = true;
    bool yes = true;
    for (int nr = r - 1; nr <= r + 1; ++nr) {
      for (int nc = c - 1; nc <= c + 1; ++nc) {
        if (nr == r && nc == c) continue;
        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if (!visited[nr][nc] && v[r][c] == v[nr][nc]) yes &= f(nr, nc);
        if (v[r][c] < v[nr][nc]) {
          yes = false;
        }
      }
    }
    return yes;
  };
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (!visited[i][j] && f(i, j)) {
        ++ans;
      }
    }
  }
  cout << ans;
}