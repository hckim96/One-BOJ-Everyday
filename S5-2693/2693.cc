#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int T; cin >> T;

  vector<int> v(10);
  while (T--) {
    for(auto& e: v) cin >> e;
    sort(all(v), greater<int>());
    cout << v[2] << '\n';
  }
}