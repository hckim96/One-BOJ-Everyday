#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    int l;
    cin >> l;

    int tmp = 36 * 36;
    int ttmp = 0;
    while (l--) {
      int s, r;
      cin >> s >> r;
      ttmp += s * r;
    }
    cout << tmp / ttmp << ' ';
    cout << 2 * tmp / ttmp << ' ';
    cout << 3 * tmp / ttmp << '\n';
  }
}