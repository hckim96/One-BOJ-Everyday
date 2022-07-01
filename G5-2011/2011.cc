#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  string s;
  cin >> s;

  vector<vector<int> > dp(s.size(), vector<int> (3, -1));

  function<int(int, int)> f = [&](int cur, int l) {
    if (cur > s.size()) return 0;

    auto& ret = dp[cur][l];
    if (ret != -1) return ret;

    if (s[cur] == '0') return ret = 0;

    auto num = stoi(s.substr(cur, l));
    if (num > 26 || num <= 0) return ret = 0;

    if (cur + l == s.size()) return ret = 1;

    return ret = (f(cur + l, 1) + f(cur + l, 2)) % 1000000;
  };

  cout << (f(0, 1) + f(0, 2)) % 1000000 << '\n';
}