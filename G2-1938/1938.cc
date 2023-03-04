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

  int n;
  cin >> n;
  vector<string> v(n);

  tuple<int, int, int> cur = {-1, -1, -1};
  tuple<int, int, int> target = {-1, -1, -1};

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    for (int j = 0; j < n; ++j) {
      if (v[i][j] == 'B') {
        auto& [a, b, c] = cur;
        if (a == -1) {
          a = i;
          b = j;
          c = -1;
        } else {
          if (c == -1) {
            c = (a == i);
          }
          a += i;
          b += j;
        }
        v[i][j] = '0';
      } else if (v[i][j] == 'E') {
        auto& [a, b, c] = target;
        if (a == -1) {
          a = i;
          b = j;
          c = -1;
        } else {
          if (c == -1) {
            c = (a == i);
          }
          a += i;
          b += j;
        }
        v[i][j] = '0';
      }
    }
  }
  auto& [a, b, c] = cur;
  a /= 3; b /= 3;
  auto& [d, e, f] = target;
  d /= 3; e /= 3;



  vector<vector<vector<int> > > vis(n, vvi(n, vi(2, 0)));
  queue<tuple<int, int, int> > q;
  q.push({a, b, c});
  vis[a][b][c] = true;
  int ans = 0;
  while (q.size()) {
    int ttmp = q.size();
    while (ttmp--) {

    auto [fa, fb, fc] = q.front();
    if (q.front() == target) {
      cout << ans << '\n';
      return 0;
    }
    q.pop();
    int fa1, fa2, fb1, fb2;
    if (fc) {
      fa1 = fa2 = fa;
      fb1 = fb - 1;
      fb2 = fb + 1;
    } else {
      fb1 = fb2 = fb;
      fa1 = fa - 1;
      fa2 = fa + 1;
    }

    if ( fa - 1 >= 0
      && !vis[fa - 1][fb][fc] 
    && fa1 - 1 >= 0
    && v[fa - 1][fb] == '0'
    && v[fa1 - 1][fb1] == '0'
    && v[fa2 - 1][fb2] == '0'
    ) {
      vis[fa - 1][fb][fc] = true;
      q.push({fa - 1, fb, fc});
    }
    if ( fa + 1 < n
      && !vis[fa + 1][fb][fc] 
    && fa2 + 1 < n
    && v[fa + 1][fb] == '0'
    && v[fa1 + 1][fb1] == '0'
    && v[fa2 + 1][fb2] == '0'
    ) {
      vis[fa + 1][fb][fc] = true;
      q.push({fa + 1, fb, fc});
    }
    if ( fb - 1 >= 0
      && !vis[fa][fb - 1][fc] 
    && fb1 - 1 >= 0
    && v[fa][fb - 1] == '0'
    && v[fa1][fb1 - 1] == '0'
    && v[fa2][fb2 - 1] == '0'
    ) {
      vis[fa][fb - 1][fc] = true;
      q.push({fa, fb - 1, fc});
    }
    if ( fb + 1 < n
      && !vis[fa][fb + 1][fc] 
    && fb2 + 1 < n
    && v[fa][fb + 1] == '0'
    && v[fa1][fb1 + 1] == '0'
    && v[fa2][fb2 + 1] == '0'
    ) {
      vis[fa][fb + 1][fc] = true;
      q.push({fa, fb + 1, fc});
    }
    if (!vis[fa][fb][!fc] 
    && (fa != 0 && fa != n - 1 && fb != 0 && fb != n - 1)
    && v[fa + 1][fb + 1] == '0'
    && v[fa + 1][fb] == '0'
    && v[fa + 1][fb - 1] == '0'
    && v[fa][fb + 1] == '0'
    && v[fa][fb - 1] == '0'
    && v[fa - 1][fb + 1] == '0'
    && v[fa - 1][fb] == '0'
    && v[fa - 1][fb - 1] == '0'
    ) {
      vis[fa][fb][!fc] = true;
      q.push({fa, fb, !fc});
    }
    }
    ++ans;
  }
  
  cout << 0;  

}