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

  vl fib(2e6 + 2, 0);
  int s = 1e6;
  fib[s] = 0;
  fib[s + 1] = 1;
  fib[s - 1] = 1;
  int MOD = 1e9;
  for (int i = 2; i <= 1e6; ++i) {
    fib[s + i] = fib[s + i - 1] + fib[s + i - 2];
    fib[s + i] %= MOD;
    fib[s - i] = fib[s - i + 2] - fib[s - i + 1];
    fib[s - i] %= MOD;
  }
  int n;
  cin >> n;

  if (fib[s + n] == 0) {
    cout << 0 << '\n' << 0;
  } else if (fib[s + n] > 0) {
    cout << 1 << '\n';
    cout << fib[s + n];
  } else {
    cout << -1 << '\n';
    cout << abs(fib[s + n]) % MOD;
  }
}