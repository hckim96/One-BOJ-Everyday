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

  int h = 0;
  int nh = 0;
  string s;
  getline(cin, s);

  for (int i = 0; i < s.size() - 2; ++i) {
    if (s[i] == ':' && s[i + 1] == '-') {
      if (s[i + 2] == ')') h++;
      else if (s[i + 2] == '(') nh++;
    }
  }
  if (h == 0 && nh == 0) {
    cout << "none";
  } else if (h == nh) {
    cout << "unsure";
  } else if (h > nh) {
    cout << "happy";
  } else {
    cout << "sad";
  }
}