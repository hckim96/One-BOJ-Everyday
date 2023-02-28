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

  int A, B, C;
  cin >> A >> B >> C;
  queue<tuple<int, int, int> > q;
  q.push({0, 0, C});
  set<tuple<int, int, int> > vis;
  set<int> ans;
  vis.insert({0, 0, C});
  while (q.size()) {
    auto [a, b, c] = q.front();
    if (a == 0) ans.insert(c);
    q.pop();

    if (a) {
      int tmp = min(B- b, a);
      if (vis.insert({a - tmp, b + tmp, c}).second) q.push({a - tmp, b + tmp, c});
      int tmp2 = min(C - c, a);
      if (vis.insert({a - tmp2, b, c + tmp2}).second) q.push({a-tmp2, b, c+tmp2});
    }
    if (b) {
      int tmp = min(A - a, b);
      if (vis.insert({a + tmp, b - tmp, c}).second) q.push({a + tmp, b - tmp, c});
      int tmp2 = min(C - c, b);
      if (vis.insert({a, b - tmp2, c + tmp2}).second) q.push({a, b- tmp2, c + tmp2});
    }
    if (c) {
      int tmp = min(A-a, c);
      if (vis.insert({a + tmp, b, c - tmp}).second) q.push({a + tmp, b , c-tmp});
      int tmp2 = min(B - b, c);
      if (vis.insert({a, b + tmp2, c - tmp2}).second) q.push({a, b + tmp2, c - tmp2});
    }
  }

  each(e, ans) cout << e << ' ';
}