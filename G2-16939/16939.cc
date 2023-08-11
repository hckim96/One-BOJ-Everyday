#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> tl;
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
  vi v(25, 0);
  for (int i = 1; i < v.size(); ++i) cin >> v[i];

  auto rotate = [&](int x) {
    vvi p =  {
      {22, 21, 18, 17, 6, 5, 14, 13},
      {3, 4, 17, 19, 10, 9, 16, 14},
      {7, 8, 19, 20, 23, 24, 15, 16},
      {1, 3, 5, 7, 9, 11, 24, 22},
      {4, 2, 21, 23, 12, 10, 8, 6},
      {2, 1, 13, 15, 11, 12, 20, 18}
    };

    rep(2) {
      auto tmp = v[p[x][0]];
      for (int i = 0; i < p[x].size(); ++i) {
        if (i == p[x].size() - 1) v[p[x][i]] = tmp;
        else v[p[x][i]] = v[p[x][i + 1]];
      }
    }
  };

  auto check = [&]() {
    for (int i = 0; i < 6; ++i) {
      if (!(
        v[4 * i + 1] == v[4 * i + 2] &&
        v[4 * i + 2] == v[4 * i + 3] &&
        v[4 * i + 3] == v[4 * i + 4] 
      )) return false;
    }

    return true;
  };

  for (int i = 0; i < 6; ++i) {
    rotate(i);
    if (check()) {cout << 1; return 0;}
    rotate(i);
    rotate(i);
    if (check()) {cout << 1; return 0;}
    rotate(i);
  }
  cout << 0;
}