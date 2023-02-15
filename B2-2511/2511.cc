#include <bits/stdc++.h>
using namespace std;

int main() {
  
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  
  vector<int> v1(10), v2(10);
  int a = 0;
  int b = 0;

  for (auto& e: v1) cin >> e;
  for (auto& e: v2) cin >> e;

  int last = 0;
  for (int i =0 ;i < 10; ++i) {
    if (v1[i] > v2[i]) {
      a += 3;
      last = 1;
    } else if (v1[i] < v2[i]) {
      b += 3;
      last = 2;
    } else {
      a += 1;
      b += 1;
    }
  }

  cout << a << ' ' << b << '\n';

  if (a > b) cout << 'A';
  else if (a < b) cout << 'B';
  else {
    if (last == 0) {
      cout << 'D';
    } else if (last == 1) {
      cout << 'A';
    } else {
      cout << 'B';
    }
  }
  

  
}