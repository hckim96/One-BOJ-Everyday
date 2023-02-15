#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r",stdin);
  freopen("../output.txt", "w", stdout);
  #endif

  int N;
  cin >> N;

  vector<int> v(1001, 0);
  for (int i = 0; i < N; ++i) {
    int n, h;
    cin >> n >> h;
    v[n] = h;
  }

  vector<int> rmax(1001, 0);
  for (int i = v.size()-  1; i >= 0; --i) {
    rmax[i] = max(rmax[i], v[i]);
    if (i < v.size() - 1) rmax[i] = max(rmax[i], rmax[i + 1]);
  }

  int cur = 0;
  int ans = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] > cur) cur = v[i];
    else if (rmax[i] < cur) cur = rmax[i];
    ans += cur;
  }
  cout << ans << '\n';
}