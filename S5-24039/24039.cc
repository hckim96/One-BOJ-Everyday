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

  int n;
  cin >> n;

  vi isPrime(1000, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < isPrime.size(); ++i) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }

  vi primes;
  for (int i = 2; i < isPrime.size(); ++i) {
    if (isPrime[i]) primes.push_back(i);
  }

  vi tmp;
  FOR (i, 0, primes.size() - 1) {
    int ret = primes[i] * primes[i + 1];
    tmp.push_back(ret);
    if (ret > n) goto here;
  }
  here:;

  cout << *upper_bound(all(tmp), n);

}