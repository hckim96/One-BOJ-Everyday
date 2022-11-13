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

  int N;
  cin >> N;
  vector<vector<int> > s(N, vector<int> (N, 0));
  for (auto& e: s) for (auto& ee: e) cin >> ee;

  vector<int> t(N, 0);
  int ans = 1e9;
  function<void(int)> f = [&](int cur) {
    if (cur == N) {
      int sum1 = 0;
      int sum2 = 0;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (t[i] && t[j]) sum1 += s[i][j];
          if (!t[i] && !t[j]) sum2 += s[i][j];
        }
      }
      ans = min(ans, abs(sum1 - sum2));
      return;
    }

    f(cur + 1);
    t[cur] = 1;
    f(cur + 1);
    t[cur] = 0;
  };

  f(0);
  cout << ans << '\n';
}