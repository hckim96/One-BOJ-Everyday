#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int a, b, c, d;
  while (cin >> a >> b >> c >> d && (a || b || c || d)) {
    int cur = a;
    int ans = 0;
    if (b <= cur) {
      ans += cur - b;
    } else {
      ans += cur + 40 - b;
    }
    cur = b;
    if (c >= cur) {
      ans += c - cur;
    } else {
      ans += c + 40 - cur;
    }

    cur = c;

    if (d <= cur) {
      ans += cur - d;
    } else {
      ans += cur + 40 - d;
    }

    ans += 40 * 3;
    ans *= 9;
    cout << ans << '\n';
  }
}