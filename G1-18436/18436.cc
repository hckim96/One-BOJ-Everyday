#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  int N;
  cin >> N;

  // # odd
  vector<int> t(2 * N, 0);
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    if (a & 1) {
      t[i + N] = 1;
    }
  }
  for (int i = N - 1; i >= 1; --i) t[i] = t[i << 1] + t[i << 1 | 1];

  auto update = [&](int p, int v) {
    for (t[p += N] = v; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  };

  auto query = [&](int l, int r) {
    int ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret += t[l++];
      if (r & 1) ret += t[--r];
    }
    return ret;
  };
  int M;
  cin >> M;

  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(b - 1, c & 1);
    } else if (a == 2) {
      cout << c - b + 1 - query(b - 1, c) << '\n';
    } else {
      cout << query(b - 1, c) << '\n';
    }
  }
}