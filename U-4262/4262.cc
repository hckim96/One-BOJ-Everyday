#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  vector<int> isPrime(1000002, 1);
  vector<int> isSemi(1000002, 0);
  for (int i = 5; i * i < isPrime.size(); i += 4) {
    if (!isPrime[i]) continue;
    for (int j = i * i; j < isPrime.size(); j += 4 * i) {
      isPrime[j] = false;
    }
  }
  for (int i = 5; i * i < isPrime.size(); i += 4) {
    if (!isPrime[i]) continue;
    for (int j = i; i * j < isPrime.size(); j += 4) {
      if (!isPrime[j]) continue;
      isSemi[i * j] = true;
    }
  }

  for (int i = 1; i < isSemi.size(); ++i) {
    isSemi[i] += isSemi[i - 1];
  }

  int H;

  while (cin >> H && H) {
    cout << H << ' ' << isSemi[H] << '\n';
  }
}