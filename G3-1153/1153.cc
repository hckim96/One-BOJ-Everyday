#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  ll N;
  cin >> N;

  vl isPrime(N + 1, 1);
  isPrime[0] = isPrime[1] = 0;
  for (ll i = 2; i * i <= N; ++i) {
    if (!isPrime[i]) continue;
    for (ll j = i * i; j <= N; j += i) {
      isPrime[j] = false;
    }
  }
  vl primes;
  queue<pair<ll, vl> > q;
  for (ll i = 0; i < isPrime.size(); ++i) {
    if (isPrime[i]) {
      primes.push_back(i);
      q.push({i, {i}});
    }
  }

  auto check = [&](int n) {
    vl ret;
    for (auto e: primes) {
      if (n - e >= 0 && isPrime[n - e]) {
        ret = {e, n - e};
        return ret;
      }
    }
    return ret;
  };
  vl ans;

  for (int i = 2; N - i >= i; ++i) {
    int l = i;
    int r = N - i;

    auto ret1 = check(l);
    auto ret2 = check(r);
    if (ret1.size() && ret2.size()) {
      ans = ret1;
      ans.push_back(ret2.front());
      ans.push_back(ret2.back());
      break;
    }
  }

  if (ans.size()) {
    sort(all(ans));
    for (auto e: ans) {
      cout << e << ' ';
    }
  } else {
    cout << -1;
  }
}