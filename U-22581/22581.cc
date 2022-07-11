#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define MOD 1'000'000'007

vector<vector<long long> > operator*(vector<vector<long long> > v1, vector<vector<long long> > v2) {
    vector<vector<long long> > ret(v1.size(), vector<long long> (v2[0].size(), 0));
    for (long long i = 0; i < ret.size(); ++i) {
        for (long long j = 0; j < ret[0].size(); ++j) {
            for (long long k = 0; k < v1[0].size(); ++k) {
                ret[i][j] = (ret[i][j] + v1[i][k] * v2[k][j]) % MOD;
            }
        }
    }
    return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  long long K;
  cin >> K;
  auto fib = [&](long long n) {
    if (n == 0) return 0LL;
    --n;
    vector<vector<long long> > ret = {{1, 0}, {0, 1}};
    vector<vector<long long> > mul = {{1, 1}, {1, 0}};
    while (n) {
        if (n & 1) {
            ret = ret * mul;
        }
        mul = mul * mul;
        n >>= 1;
    }
    return ret[0][0];
  };

  // i 열 대각선 까지 누적개수
  auto f = [&](long long i) {
    if (i & 1) return ((i/2) + 1) * ((i/2) + 1);
    else return (i/2) * ((i/2) + 1);
  };

  // 무슨 열 인지 찾기
  long long lo = 0;
  long long hi = 3e9;
  while (lo + 1 < hi) {
    long long mid = lo + hi >> 1;
    if (f(mid) < K) lo = mid;
    else hi = mid;
  }
  long long idx = hi;
  auto prevNum = f(idx - 1);
  long long partOrder = K - prevNum;
  long long r = 1;
  long long c = idx;

  if (idx % 2 == 0) {
    r += 2 * (partOrder - 1);
    c -= 2 * (partOrder - 1);
  } else {
    r += 2 * (partOrder - 1);
    c -= 2 * (partOrder - 1);
    if (r > c) {
      r -= 1;
      c += 1;
    }
  }

  cout << fib(r + 1) * fib(c + 1) % MOD << '\n';
}
