#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  string s;
  cin >> s;

  string ans = s + "0000";
  int up = 0;
  for (int i = 0; i < max(s.size(), ans.size()); ++i) {
    int c1 = 0;
    int c2 = 0;
    c1 = ans[ans.size() - 1 - i] - '0';
    if (s.size() - 1 >= i)
    c2 = s[s.size() - 1 - i] - '0';

    int sum = c1 + c2 + up;
    up = sum / 2;

    ans[ans.size() - 1 - i] = '0' + (sum % 2);
  }

  if (up) ans = "1" + ans;
  cout << ans << '\n';
}