#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  vector<vector<int> > v(101, vector<int> (101, 0));

  int N;
  cin >> N;

  while (N--) {
    int r, c;
    cin >> r >> c;
    for (int rr = r; rr < r + 10; ++rr) {
      for (int cc = c; cc < c + 10; ++ cc) {
        v[rr][cc] = 1;
      }
    }
  }
  int ans = 0;
  for (auto e: v) for (auto ee: e) ans += ee;
  cout << ans << '\n';
}