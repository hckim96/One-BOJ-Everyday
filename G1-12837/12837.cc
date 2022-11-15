#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N, Q;
  cin >> N >> Q;

  vector<long long> t(2 * N, 0);

  auto update = [&](int p, long long val) {
    for (t[p += N] += val; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  };
  auto query = [&](int l, int r) {
    long long ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret += t[l++];
      if (r & 1) ret += t[--r];
    }
    return ret;
  };

  while (Q--) {
    long long a, b, c;
    cin >> a >> b >> c;
    if (a == 1) {
      update(b - 1, c);
    } else {
      cout << query(b - 1, c) << '\n';
    }
  }
}