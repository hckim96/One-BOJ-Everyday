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
  while (cin >> N >> K) {
    vector<int> t(2 * N);
    for (int i = 0; i < N; ++i) {
      int a;
      cin >> a;
      if (a == 0) {
        t[i + N] = 0;
      } else if (a < 0) {
        t[i + N] = -1;
      } else {
        t[i + N] = 1;
      }
    }
    for (int i = N - 1; i >= 1; --i) t[i] = t[i << 1] * t[i << 1 | 1];

    auto update = [&](int p, int v) {
      if (v < 0) v = -1;
      if (v > 0) v = 1;
      for (t[p += N] = v; p > 1; p >>= 1) t[p >> 1] = t[p] * t[p ^ 1];
    };

    auto query = [&](int l, int r) {
      int ret = 1;
      for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret *= t[l++];
        if (r & 1) ret *= t[--r];
      }
      return ret;
    };

    while (K--) {
      char a;
      int b, c;
      cin >> a >> b >> c;
      if (a == 'C') {
        update(b - 1, c);
      } else {
        auto ret = query(b - 1, c);
        if (ret == 0) {
          cout << '0';
        } else if (ret < 0) {
          cout << '-';
        } else { 
          cout << '+';
        }
      }
    }
    cout << '\n';
  }
}