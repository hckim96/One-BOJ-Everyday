#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  long long N;
  while (cin >> N && N != -1) {
    auto check = [&](long long n, long long k) {
      long long tmp = k;
      while (tmp--) {
        n -= 1;
        if (n % k != 0) return false;
        n -= n / k;
      }
      if (n % k != 0) return false;
      return true;
    };

    for (int k = N - 1; k > 1; --k) {
      if (check(N, k)) {
        cout << N << " coconuts, " << k << " people and 1 monkey\n";
        goto u;
      }
    }

    cout << N << " coconuts, no solution\n";
    u:;
  }
}