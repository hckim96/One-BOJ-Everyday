#include <bits/stdc++.h>

using namespace std;

int main() {
  int a = 0;
  int b= 0 ;
  int TC; cin >> TC;
  while (TC--) {
    int aa, bb;
    cin >> aa >> bb;
    if (aa > bb) ++a;
    if (bb > aa) ++ b;
  }
  cout << a << ' ' << b;
}