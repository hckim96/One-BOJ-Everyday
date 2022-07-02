#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N;
  cin >> N;

  vector<vector<int> > cost(N, vector<int> (N));
  for (auto& e: cost) for (auto& ee: e) cin >> ee;

  string s;
  cin >> s;
  int num = 0;
  int tmp = 1;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'Y') {
      num |= tmp;
    }
    tmp <<= 1;
  }

  int P; cin >> P;
  int ans = 1e9;
  vector<int> dp(1 << s.size(), 1e9);
  dp[num] = 0;
  queue<pair<int, int> > q;

  q.push({num, dp[num]});
  auto countOnes = [&](int n) {
    int ones = 0;
    while (n) {
      if (n & 1) ones++;
      n >>=1;
    }
    return ones;
  };

  while (q.size()) {
    auto [f, d] = q.front();
    q.pop();
    if (dp[f] < d) continue;
    if (countOnes(f) >= P) {
      ans = min(ans, d);
      continue;
    }

    for (int i = 0; i < s.size(); ++i) {
      if ((f & (1 << i)) == 0) {
        int nn = f | (1 << i);
        int flag = false;
        for (int j = 0; j < s.size(); ++j) {
          if ((f & (1 << j))) {
            if (dp[nn] > d + cost[j][i]) {
              dp[nn] = d + cost[j][i];
              flag = true;
            }
          }
        }
        if (flag) q.push({nn, dp[nn]});
      }
    }
  }

  if (ans == 1e9) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
  }

}