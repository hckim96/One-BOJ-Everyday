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

  int N;
  cin >> N;
  vector<string> v(N, "");
  vector<pair<int, int> > tpos;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c;
      cin >> c;
      if (c == 'T') tpos.push_back({i, j});
      v[i] += c;
    }
  }

  auto checkT = [&](int r, int c) {
    for (int dir = 0; dir < 4; ++dir) {
      for (int k = 1; ; ++k) {
        int nr = r + dr[dir] * k;
        int nc = c + dc[dir] * k;

        if (nr < 0 || nr >= N || nc < 0 || nc >= N) break;
        if (v[nr][nc] == 'O') break;
        if (v[nr][nc] == 'S') return false;
      }
    }
    return true;
  };

  auto check =[&](vector<int>& selected) {
    vector<pair<int, int> > pos;
    for (auto e: selected) {
      pos.push_back({e / N, e % N});
    }
    for (auto [r, c]: pos) {
      if (v[r][c] != 'X') return false;
    }

    for (auto [r, c]: pos) v[r][c] = 'O';

    bool ret = true;

    for (auto [r, c]: tpos) {
      // 4 dir
      ret = ret && checkT(r, c);
    }


    for (auto [r, c]: pos) v[r][c] = 'X';
    return ret;
  };

  bool yes = false;
  function<void(int, vector<int>&)> f = [&](int cur, vector<int>& selected) {
    if (selected.size() == 3) {
      if (check(selected)) {
        yes = true;
      }
      return;
    }
    if (cur >= N * N) return;


    selected.push_back(cur);
    f(cur + 1, selected);
    selected.pop_back();
    f(cur + 1, selected);
  };

  vector<int> selected;
  f(0, selected);
  if (yes) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

}