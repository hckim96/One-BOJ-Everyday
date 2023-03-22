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

  pair<ld, ld> A, B, C, D;
  cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;

  auto vec = [&](pair<ld, ld>& p1, pair<ld, ld>& p2) {
    pair<ld, ld> ret = p2;
    ret.first -= p1.first;
    ret.second -= p1.second;
    return ret;
  };
  auto dot = [&](pair<ld, ld>& p1, pair<ld, ld>& p2) {
    ld ret = p1.first*p2.first + p1.second * p2.second;
    return ret;
  };

  auto AC = vec(A, C);
  auto BD = vec(B, D);
  auto ACBD = vec(AC, BD);
  auto calc = [&](ld t) {
    return sqrtl(dot(AC, AC) + 2 * t * dot(ACBD, AC) + t * t * dot(ACBD, ACBD));
  };

  ld ans = min(calc(0), calc(1));
  ld tmin = - (dot(ACBD, AC) / dot(ACBD, ACBD));
  if (tmin > 0 && tmin < 1) {
    ans = min(ans, calc(tmin));
  }
  cout.precision(6);
  cout << fixed;
  cout << ans << '\n';
}