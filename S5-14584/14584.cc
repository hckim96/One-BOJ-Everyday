#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  
  string str;
  cin >> str;

  int n;
  cin >> n;

  vector<string> v(n);
  for (auto& e: v) cin >> e;

  for (int i = 0; i < 26; ++i) {
    auto check = [&](string s) {
      for (int k = 0; k < str.size(); ++k) {
        bool ret = true;
        for (int l = 0; l < s.size(); ++l) {
          if (str[k + l] != (s[l] + i - 'a') % 26 + 'a') {
            ret = false;
            break;
          }
        }
        if (ret) return true;
      }
      return false;
    };
    int found = false;
    for (int j = 0; j < n; ++j) {
      if (check(v[j])) {
        found = true;
        break;
      }
    }
    
    if (found) {
      for (auto e: str) {
        auto ee = (e - i - 'a') % 26;
        if (ee < 0) ee += 26;
        cout << char(ee + 'a');
      }
      cout << '\n';
      break;
    }

  }
}