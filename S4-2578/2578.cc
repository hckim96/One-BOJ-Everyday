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

  vvl v(5, vl(5));
  each(e,v) each(ee, e) cin >> ee;

  ll ans = 0;
  F0R(i,5)F0R(j,5) {
    ll n;
    cin >> n;
    ++ans;
    // find and mark
    F0R(ii, 5) F0R(jj, 5) if (v[ii][jj] == n) v[ii][jj] = -1;
    // check

    ll bingnum = 0;
    F0R(ii, 5) {
      ll bing = 1;
      F0R(jj, 5) {
        if (v[ii][jj] != -1) bing = 0;
      }
      bingnum += bing;
    }

    F0R(ii, 5) {
      ll bing = 1;
      F0R(jj, 5) {
        if (v[jj][ii] != -1) bing = 0;
      }
      bingnum += bing;
    }

    if (v[0][0] == -1 && v[1][1] ==-1 && v[2][2] == -1 && v[3][3] == -1 && v[4][4] == -1) bingnum++;
    if (v[0][4] == -1 && v[1][3] ==-1 && v[2][2] == -1 && v[3][1] == -1 && v[4][0] == -1) bingnum++;

    if (bingnum >= 3) goto done;
  }

  done:
  cout << ans;
}