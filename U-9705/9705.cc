#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  long long T;
  long long idx = 1;
  while (cin >> T && T) {
    T -= 3;
    vector<vector<long long> > dp(T + 1, vector<long long> (4, -1));

    function<long long(long long, long long)> p = [&](long long n, long long m) {

      if (n == m)
        return 1LL + p(n, m - 1);
      if (m == 0 || n < 0)
          return 0LL;
      if (n == 0 || m == 1)
          return 1LL;
      if (dp[n][m] != -1) return dp[n][m];
      return dp[n][m] = p(n, m - 1) + p(n - m, m);
    };
    long long ans = p(T, 3);
    ans -= T / 2 + 1;
    cout << "Case #"<< idx++ << ": " << T + 3 << ":";
    cout << ans << '\n';
  }
}