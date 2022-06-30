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
    int n;
    cin >> n;

    int bit = 0;
    while (n) {
      if (n & 1) {
        cout << bit << ' ';
      }
      n >>= 1;
      bit++;
    }
    cout << '\n';
  }
}