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

  ll n;
  cin >> n;

  vector<pair<int, pair<int, int> > > v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second.first >> v[i].second.second;
  }

  ll ans = 0;

  for (int i = 1; i < 10; ++i) {
    for (int j = 1; j < 10; ++j) {
      if (i == j) continue;
      for (int k = 1; k < 10; ++k) {
        if (j == k) continue;
        if (i == k) continue;

        // check 
        int yes = 1;
        for (auto [num, res]: v) {
          pair<int, int> tmpres = {0, 0};

          int ii = num / 100;
          int jj = num % 100 / 10;
          int kk = num % 10;

          if (ii == i) tmpres.first++;
          else if (ii == j || ii == k) tmpres.second++;
          if (jj == j) tmpres.first++;
          else if (jj == i || jj == k) tmpres.second++;
          if (kk == k) tmpres.first++;
          else if (kk == i || kk == j) tmpres.second++;


          if (tmpres.first != res.first || tmpres.second != res.second) {
            yes = 0;
            break;
          }
        }
        ans += yes;
      }
    }
  }

  cout << ans;
}