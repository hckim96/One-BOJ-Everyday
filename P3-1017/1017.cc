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

  set<int> primes;
  vi isPrime(2000, 1);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < isPrime.size(); ++i) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }
  for (int i = 0; i < isPrime.size(); ++i) if (isPrime[i]) primes.insert(i);

  int n;
  cin >> n;
  vi v(n);
  each(e, v) cin >> e;

  vvi adj(n);

  for (int i = 0; i < v.size(); ++i) {
    for (int j = i + 1; j < v.size(); ++j) {
      if (primes.count(v[i] + v[j])){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int x = 10;
  vi vis(n);
  vi matchInfo(n, -1);
  function<int(int)> f = [&](int x) {
    if (vis[x]) return false;
    vis[x] = true;
    for (auto e: adj[x]) {
      if (matchInfo[e] == -1|| (!vis[matchInfo[e]] && f(matchInfo[e]))) {
        vis[e] = true;
        matchInfo[e] = x;
        return true;
      }
    }
    return false;
  };

  vi ans;
  for (auto e: adj[0]) {
    fill(all(matchInfo), -1);
    matchInfo[e] = 0;
    int matched = 0;
    for (int i = 1; i < n; ++i) {
      fill(all(vis), false);
      vis[0] = true;
      matched += f(i);
    }
    if (matched == n - 1) {
      ans.push_back(v[e]);
    }
  }

  if (ans.size()) {
    sort(all(ans));
    each(e, ans) cout << e << ' ';
  } else {
    cout << -1;
  }
}