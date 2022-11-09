#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int A, B, C;
  cin >> A >> B >> C;
  auto ans = A + B;
  if (ans >= 2 * C) ans -= 2 * C;
  cout << ans << '\n';
}