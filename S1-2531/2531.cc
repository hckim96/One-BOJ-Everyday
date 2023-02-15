#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif

  int N, d, k , c;
  cin >> N >> d >> k >> c;
  vector<int> v(N);
  for (auto& e: v) cin >> e;

  int kind = 0;
  int ans = 0;
  map<int, int> m;
  for (int i = 0; i < k; ++i) {
    if (++m[v[i]] == 1) kind++;
    ans = max(ans, kind + (m[c] == 0));
  }
  for (int l = 0; l < N - 1; ++l) {
    int r = l + k;
    if (--m[v[l]] == 0) --kind;
    if (++m[v[r % N]] == 1) ++kind;
    ans = max(ans, kind + (m[c] == 0));
  }
  cout << ans << '\n';
}