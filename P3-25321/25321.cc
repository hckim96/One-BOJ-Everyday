#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> t;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
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

  const ll MAX_N = 3e5 + 10;
  const ll MOD = 1e9 + 7;
  vl fact(MAX_N, 1);
  for (int i = 1; i < MAX_N; ++i) {
    fact[i] = i * fact[i - 1] % MOD;
  }
  auto power = [&](ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1) ret = ret * a % MOD;
      a = a * a % MOD;
      b >>= 1;
    }
    return ret;
  };
  auto inv = [&](ll a) {
    return power(a, MOD - 2);
  };
  auto ncr = [&](ll n, ll r) {
    ll ret = fact[n];
    ll denom = fact[r] * fact[n - r] % MOD;
    ret = ret * inv(denom) % MOD;
    return ret;
  };
  auto catalan = [&](ll n) {
    // Calculate value of 2nCn
    ll c = ncr(2 * n, n);
 
    // return 2nCn/(n+1)
    // return c / (n + 1);
    return c * inv(n + 1) % MOD;
  };

  ll ans = 1;
  stack<char> st;

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != '?' && s[i] != ':') continue;

    if (s[i] == ':') {
      if (st.size() && st.top() == ':') {
        ll cnt = 0;
        while (st.size() >= 3) {
          auto prev = st.top(); st.pop();
          auto pprev = st.top();
          if (pprev == '?' && prev == ':') {
            ++cnt;
            st.pop();
          } else {
            st.push(prev);
            break;
          }
        }
        ans = ans * catalan(cnt) % MOD;
      }
    }
    st.push(s[i]);
  }

  ll cnt = 0;
  while (st.size()) {
    auto prev = st.top(); st.pop();
    auto pprev = st.top();
    if (pprev == '?' && prev == ':') {
      ++cnt;
      st.pop();
    } else {
      st.push(prev);
      break;
    }
  }

  ans = ans * catalan(cnt) % MOD;
  cout << ans;
}