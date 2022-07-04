#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, M;
  cin >> N >> M;
  vector<long long> t(2 * N, 0);

  // [s, e)
  auto query = [&](int s, int e) {
    long long ret = 0;
    for (s += N, e += N; s < e; s >>= 1, e >>= 1) {
      if (s & 1) ret += t[s++];
      if (e & 1) ret += t[--e];
    }
    return ret;
  };

  auto update = [&](int p, int v) {
    for (t[p += N] = v; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  };

  while (M--) {
    int a, i, j;
    cin >> a >> i >> j;
    if (a == 0) {
      if (i > j) swap(i, j);
      //sum
      cout << query(i - 1, j) << '\n';
    } else {
      //modify
      update(i - 1, j);
    }
  }
}