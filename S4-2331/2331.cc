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

  ll A, P;
  cin >> A >> P;

  set<ll> s;
  map<ll, int> mp;

  s.insert(A);
  ll idx = 0;
  mp[A] = idx++;

  while (true) {
    ll tmp = A;
    ll next = 0;

    while (tmp > 0) {
      ll ttmp = 1;
      for (int i = 0; i < P; ++i) ttmp *= tmp % 10;
      tmp /= 10;
      next += ttmp;
    }
    
    if (s.count(next)) {
      cout << mp[next] << '\n';
      break;
    }
    s.insert(next);
    mp[next] = idx++;
    A = next;
  }
}