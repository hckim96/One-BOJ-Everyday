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

  int N;
  cin >> N;
  vector<int> a(N);

  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  sort(all(a));

  vector<int> good(N, 0);
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == j) continue;
      if (good[j]) continue;

      int diff = a[j] - a[i];

      int cnt = upper_bound(all(a), diff) - lower_bound(all(a), diff);
      int should = 1;
      if (diff == a[i]) should++;
      if (diff == a[j]) should++;

      if (cnt >= should) {
        good[j] = true;
        ans++;
      }
    }
  }

  cout << ans << '\n';
}
