#include <bits/stdc++.h>

using namespace std;

int main() {
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif

  int a, b, c;
  cin >> a >> b >> c;

  int N;
  cin >> N;


  int ans = 0;

  for (int i = 0; i <= N / a; ++i) {
    for (int j = 0; j <= N / b; ++j) {
      for (int k = 0; k <= N / c; ++k) {
        if (a * i + b * j + c * k == N) {
          ans = 1;
          goto done;
        }
      }
    }
  }

  done:
  cout << ans << '\n';
}