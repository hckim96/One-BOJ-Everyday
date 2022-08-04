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

    bool ispal = true;
    int idx;
    for (int i = 0; i < s.size() - i - 1; ++i) {
      if (s[i] != s[s.size() - i - 1]) {
        ispal = false;
        idx = i;
        break;
      }
    }

    if (ispal) {
      cout << 0 << '\n';
      continue;
    }

    int l = idx;
    int r = s.size() - l - 1;

    ispal = true;
    int ll = l + 1;
    int rr = r;
    while (ll < rr) {
      if (s[ll] != s[rr]) {
        ispal = false;
        break;
      }
      ++ll;
      --rr;
    }

    if (ispal) {
      cout << 1 << '\n';
      continue;
    }

    ispal = true;
    ll = l;
    rr = r - 1;
    while (ll < rr) {
      if (s[ll] != s[rr]) {
        ispal = false;
        break;
      }
      ++ll;
      --rr;
    }
    if (ispal) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
}