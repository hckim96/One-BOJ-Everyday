#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v1(10), v2(10);

  int a = 0;
  int b= 0;
  for (auto& e: v1) cin >> e;
  for (auto& e: v2) cin >> e;

  for (int i = 0; i < v1.size(); ++i) {
    if (v1[i] > v2[i]) ++a;
    else if (v1[i] < v2[i]) ++b;
  }
  if (a > b) cout << 'A';
  else if (a < b ) cout << 'B';
  else cout << 'D';
}
