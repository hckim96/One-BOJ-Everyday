#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, d, k, c;
  cin >> N >> d >> k >> c;
  vector<int> v(N);
  for (auto& e: v) cin >> e;


  int ans = 0;

  int kind = 0;
  vector<int> cnt(d + 1, 0);

  for (int i = 0; i < k; ++i) {
    cnt[v[i]]++;
    if (cnt[v[i]] == 1) kind++;
  }
  ans = max(ans, kind + (cnt[c] == 0));
  for (int i = 1; i < N; ++i) {
    if (--cnt[v[i - 1]] == 0) kind--;
    if (++cnt[v[(i + k - 1) % N]] == 1) kind++;
    ans = max(ans, kind + (cnt[c] == 0));
  }
  cout << ans << '\n';
}