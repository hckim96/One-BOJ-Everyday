#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, M;
  cin >> N >> M;
  set<int> a;
  while (N--) {
    int n;
    cin >> n;
    a.insert(n);
  }
  int ans = 2e9 + 1;
  for (auto e: a) {
    auto it = a.lower_bound(e + M);
    if (it != a.end()) {
      ans = min(ans, *it - e);
    }
  }
  cout << ans << '\n';
}