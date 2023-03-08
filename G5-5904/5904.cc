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

  ll n;
  cin >> n;
  vl l(1);
  l[0] = 3;

  while (true) {
    int idx = l.size();
    ll tmp = l.back() * 2 + idx + 3;
    if (tmp > 1e9) break;
    l.push_back(tmp);
  }

  while (true) {
    auto it = lower_bound(all(l), n);

    if (it == l.begin()) {
      cout << (n == 1 ? "m" : "o");
      return 0;
    }
    auto idx = it - l.begin();
    if (n > *(it - 1) + 3 + idx) {
      n -= *(it - 1) + 3 + idx;
    } else {
      if (n == *(it - 1) + 1) cout << "m";
      else cout << "o";
      return 0;
    }
  }
}