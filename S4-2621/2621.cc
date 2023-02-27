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

  vector<pair<int, char> > v(5);
  map<int, int> cntD;
  map<char, int> cntC;
  FOR(i, 0, 5) {
    cin >> v[i].second >> v[i].first;
    cntC[v[i].second]++;
    cntD[v[i].first]++;
  }

  sort(all(v));

  int ans = 0;
  if (cntC.size() == 1 && cntD.size() == 5 && v.front().first + 4 == v.back().first) {
    ans = max(ans, v.back().first + 900);
  }

  if (cntD.size() == 2 && (cntD.begin() -> second == 4 || cntD.begin() -> second == 1)) {
    for (auto [k, v]: cntD) {
      if (v == 4) ans = max(ans, k + 800);
    }
  }

  if (cntD.size() == 2 && (cntD.begin() -> second == 3 || cntD.begin() -> second == 2)) {
    int tmp = 700;
    for (auto [k, v]: cntD) {
      if (v == 3) tmp += k * 10;
      if (v == 2) tmp += k;
    }
    ans = max(ans, tmp);
  }

  if (cntC.size() == 1) ans = max(ans, v.back().first + 600);

  if (cntD.size() == 5 && v.front().first + 4 == v.back().first) ans = max(ans, v.back().first + 500);

  for (auto [k, v]: cntD) {
    if (v == 3) ans = max(ans, 400 + k);
  }

    vi val;
    for (auto [k, v]: cntD) {
      if (v >= 2) {
        val.push_back(k);
      }
    }
    if (val.size() == 2) {
      sort(all(val));
      ans = max(ans, val.front() + val.back() * 10 + 300);
    } else if (val.size() == 1) {
      ans = max(ans, val.front() + 200);
    }

    ans = max(ans, v.back().first + 100);

    cout << ans;
}