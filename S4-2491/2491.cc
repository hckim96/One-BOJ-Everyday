#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  
  int n;
  cin >> n;

  vector<int> v(n);
  for (auto& e: v) cin >> e;
  int ans=1;
  int tmp = 0;
  int prev = 0;
  for (int i = 0; i < v.size(); ++i) {
    if (prev <= v[i]) {
      ++tmp;
      ans= max(ans, tmp);
    } else {
      tmp=1;
    }
    prev = v[i];
  }
  prev = 0;
  tmp = 0;
  for (int i = v.size() - 1; i >= 0; --i) {
    if (prev <= v[i]) {
      ++tmp;
      ans= max(ans, tmp);
    } else {
      tmp = 1;
    }
    prev = v[i];
  }
  cout << ans << '\n';
}