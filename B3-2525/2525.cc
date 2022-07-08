#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int A, B, C;
  cin >> A >> B >> C;

  int h = C / 60;
  int m = C % 60;
  B += m;
  A += h + B / 60;
  A %= 24;
  B %= 60;
  cout << A << ' ' << B << '\n';
}