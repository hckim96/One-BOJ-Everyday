#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, K;
  cin >> N >> K;

  map<int, int> m;
  while (N--) {
    int a;
    cin >> a;
    m[a]++;
  }

  for (auto [a, b]: m) {
    if (b % K) {
      cout << a << '\n';
      break;
    }
  }
}