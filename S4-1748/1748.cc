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
  cin >> N;

  long long ans = 0;
  long long tmp = 1e8;
  long long digit = 9;

  while (N) {
    if (N >= tmp) {
      ans += (N - tmp + 1) * digit;
      N = tmp - 1;
    }
    tmp /= 10;
    digit -= 1;
  }

  cout << ans << '\n';
}