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

  int w,h;
  cin >> w >> h;
  vector<int> ws;
  vector<int> hs;
  ws.push_back(0);
  ws.push_back(w);
  hs.push_back(0);
  hs.push_back(h);
  int TC; cin >> TC;
  while (TC--) {
    int t, i;
    cin >> t >> i;
    if (t) ws.push_back(i);
    else hs.push_back(i);
  }
  sort(all(ws));
  sort(all(hs));
  int wmax = 0;
  int hmax = 0;
  for (auto it = ws.begin(); it + 1 != ws.end(); ++it) wmax = max(wmax, *(it + 1) - *it);
  for (auto it = hs.begin(); it + 1 != hs.end(); ++it) hmax = max(hmax, *(it + 1) - *it);
  cout << wmax * hmax;
}