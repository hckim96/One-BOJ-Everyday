#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  vector<long long> prime;
  vector<int> isPrime(sqrt(2e9) + 1, true);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < isPrime.size(); ++i) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < isPrime.size(); j += i) {
      isPrime[j] = false;
    }
  }
  for (int i = 2; i < isPrime.size(); ++i) {
    if (isPrime[i]) prime.push_back(i);
  }

  // 1 이상 x 이하 제곱 ㄴㄴ 수 개수
  auto getNum = [&](long long x) {
    // cnt, idx, num
    queue<tuple<int, int, long long> > q;
    for (int i = 0; i < prime.size(); ++i) {
      auto e = prime[i];
      if (e * e > x) break;
      q.push({1, i, e});
    }

    long long ret = 0;
    map<int, int> visited;
    while (q.size()) {
      auto [fcnt, fidx, fn] = q.front();
      q.pop();

      ret += (fcnt & 1 ? 1LL : -1LL) * (x / (fn * fn));

      for (int i = fidx + 1; i < prime.size(); ++i) {
        auto e = prime[i];
        if (fn * e * fn * e > x) break;
        if (fn % e == 0) continue;
        q.push({fcnt + 1, i, fn * e});
      }
    }
    return x - ret;
  };

  long long lo = 0;
  long long hi = 2e9;

  long long K;
  cin >> K;
  while (lo + 1 < hi) {
    long long mid = (lo + hi) >> 1;
    if (getNum(mid) < K) lo = mid;
    else hi = mid;
  }
  cout << hi << '\n';
}