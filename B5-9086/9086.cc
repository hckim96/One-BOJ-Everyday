#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int TC; cin >> TC;
  while (TC--) {
    string s;
    cin >> s;
    cout << s[0] << s[s.size() - 1] << '\n';
  }
}