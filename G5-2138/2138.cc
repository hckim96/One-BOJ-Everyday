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
  string s;
  string s2;
  cin >> s >> s2;
  string s3(s);

  auto f = [&](char c) {
    return c == '0' ? '1' : '0';
  };
  int ret = 0;
  for (int i = 1; i < n; ++i) {
    if (s[i - 1] != s2[i - 1]) {
      ret++;
      s[i] = f(s[i]);
      if (i) s[i - 1] = f(s[i - 1]);
      if (i != n - 1) s[i + 1] = f(s[i + 1]);
    }
  }
  int ret2 = 1;
  s3[0] = f(s3[0]);
  s3[1] = f(s3[1]);
  for (int i = 1; i < n; ++i) {
    if (s3[i - 1] != s2[i - 1]) {
      ret2++;
      s3[i] = f(s3[i]);
      if (i) s3[i - 1] = f(s3[i - 1]);
      if (i != n - 1) s3[i + 1] = f(s3[i + 1]);
    }
  }

  if (s.compare(s2) && s2.compare(s3)) {
    cout << -1;
  } else if (s.compare(s2)==0 && s3.compare(s2)==0 ) {
    cout << min(ret, ret2);
  } else {
    if (s.compare(s2) == 0) {
      cout << ret;
    } else {
      cout << ret2;
    }
  }

}