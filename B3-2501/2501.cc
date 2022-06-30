#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      --k;
      if (k == 0) {
        cout << i << '\n';
        return 0;
      }
    }
  }

  cout << 0 << '\n';
}