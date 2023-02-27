#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pii;
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

  int TC = 4;
  while (TC--) {
    ll ans = 0;

    vi res(18);
    each(e, res) cin >> e;
    
    vvi v(6, vi(6, 0));
    function<void(int, int, vi&)> f = [&](int i, int j, vi& resTmp) {
      if (i == 5) {
        FOR(ii, 0, 18) {
          if (resTmp[ii] != res[ii]) return;
        }
        ans = 1;
        return;
      }

      int ni, nj;
      if (j == 5) ni = i + 1, nj = ni + 1;
      else ni = i, nj = j + 1;

      for (int k = -1; k < 2; ++k) {
        if (k == -1) {
          if (resTmp[3 * i + 2] == res[3 * i + 2]) continue;
          if (resTmp[3 * j] == res[3 * j]) continue;
          resTmp[3 * i + 2]++;
          resTmp[3 * j]++;
          f(ni, nj, resTmp);
          resTmp[3 * i + 2]--;
          resTmp[3 * j]--;
        } else if (k == 0) {
          if (resTmp[3 * i + 1] == res[3 * i + 1]) continue;
          if (resTmp[3 * j + 1] == res[3 * j + 1]) continue;
          resTmp[3 * i + 1]++;
          resTmp[3 * j + 1]++;
          f(ni, nj, resTmp);
          resTmp[3 * i + 1]--;
          resTmp[3 * j + 1]--;
        } else {
          if (resTmp[3 * i] == res[3 * i]) continue;
          if (resTmp[3 * j + 2] == res[3 * j + 2]) continue;
          resTmp[3 * i]++;
          resTmp[3 * j + 2]++;
          f(ni, nj, resTmp);
          resTmp[3 * i]--;
          resTmp[3 * j + 2]--;
        }
      }
    };

    vi resTmp(18);
    f(0, 1, resTmp);
    
    cout << ans << ' ';
  }
}