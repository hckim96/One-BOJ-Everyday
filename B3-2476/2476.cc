#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N;
  cin >> N;
  int ans = 0;
  for (int i =0; i < N; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    int tmp = 0;
    if (a == b && b == c) {
      tmp = 10000 + a * 1000;
    } else if (a != b && b != c && a != c) {
      tmp = max({a, b, c}) * 100;
    } else {
      if (a == b || a == c) {
        tmp = 1000 + a * 100;
      } else if (b == c) {
        tmp = 1000 + b * 100;
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
}
