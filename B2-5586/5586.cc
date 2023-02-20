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

  string s;
  cin >> s;
  auto check = [&](int cur) {
    if (cur + 2 >= s.size()) return false;

    return s[cur + 1] == 'O' && s[cur + 2] == 'I';
  };
  ll ans1 = 0;
  ll ans2 = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'J') {
      ans1 += check(i);
    } else if (s[i] == 'I') {
      ans2 += check(i);
    }
  }
  cout << ans1 << '\n';
  cout << ans2 << '\n';
}