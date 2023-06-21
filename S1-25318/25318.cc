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

  int n;
  cin >> n;
  if (n == 0) {
    cout << 0;
    return 0;
  }

  vpl v(n);
  FOR(i, 0, n) {
    string s1, s2;
    cin >> s1 >> s2 >> v[i].second;

    ll year = stol(s1.substr(0, 4));
    ll month = stol(s1.substr(5, 2));
    ll day = stol(s1.substr(8));
    ll hour = stol(s2.substr(0, 2));
    ll minute = stol(s2.substr(3, 2));
    ll second = stol(s2.substr(6));
    
    v[i].first += second;
    v[i].first += minute * 60;
    v[i].first += hour * 60 *  60;
    v[i].first += (day - 1) * 60 *  60 * 24;
    vi daynum = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int j = 1; j < month; ++j) {
      if (j == 2 && year == 2020) {
        v[i].first += 1LL * 60 *  60 * 24 * 29;
      } else {
        v[i].first += 1LL * 60 *  60 * 24 * daynum[j];
      }
    }

    for (int j = 2019; j < year; ++j) {
      if (j == 2020) v[i].first += 60 * 60 * 24 * 366;
      else v[i].first += 60 * 60 * 24 * 365;
    }
  }

  ld x1 = 0;
  ld x2 = 0;
  FOR (j, 0, n) {
    ld p = max( powl(0.5, 1.0L * (v[n-1].first - v[j].first) / (60 * 60 * 24 * 365)), powl(0.9, n - j - 1));
    x1 += p * v[j].second;
    x2 += p;
  }
  cout << (int)roundl(x1 / x2);
}