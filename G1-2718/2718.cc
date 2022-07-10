#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define MOD 1'000'000'000

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
  
  long long a, b;
  cin >> a >> b;


  auto f = [&](long long n) {
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

  long long ret = f(b + 2) - f (a + 1);
  ret %= MOD;
  if (ret < 0) ret += MOD;
  cout << ret << '\n';
} 