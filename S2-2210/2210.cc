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

  set<string> st;

  vector<vector<char> > v(5, vector<char> (5, 0));

  for (auto& e: v) for (auto& ee: e) cin >> ee;

  function<void(int, int, string&)> f = [&](int r, int c, string& s) {
    if (s.size() == 6) {
      st.insert(s);
      return;
    }

    for (int dir = 0; dir < 4; ++dir) {
      int nr = r + dr[dir];
      int nc = c + dc[dir];

      if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
      s += v[nr][nc];
      f(nr, nc, s);
      s.pop_back();
    }
  };

  string s = "";
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      s += v[i][j];
      f(i, j, s);
      s.pop_back();
    }
  }
  cout << st.size() << '\n';
}