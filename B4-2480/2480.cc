#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int a, b, c;
  cin >> a >> b >> c;

  int ans = 0;
  if (a == b && b == c) {
    ans = 10000 + a * 1000;
  } else if (a != b && b != c && a != c) {
    ans = max({a, b, c}) * 100;
  } else {
    if (a == b) {
      ans = 1000 + a * 100;
    } else {
      ans = 1000 + c * 100;
    }
  }

  cout << ans << '\n';
}