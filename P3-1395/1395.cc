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
  N = 1;

  while (N < int(1e6 + 1)) {
      N <<= 1;
  }
  vector<long long> t(2 * N, 0);
  vector<long long> lazy(2 * N, 0);
  auto propagate = [&](int n, int ns, int ne) {
    if (lazy[n] != 0) {
        if (n < t.size() / 2) {
            lazy[n << 1] ^= lazy[n];
            lazy[n << 1 | 1] ^= lazy[n];
        }
        t[n] = ne - ns - t[n];
        lazy[n] = 0;
    }
  };
  // [l, r)
  function<void(int, int, int, int, int, int)> flip = [&](int l, int r, int v, int n, int ns, int ne) {
      propagate(n, ns, ne);
      if (r <= ns || ne <= l) return;
      if (l <= ns && ne <= r) {
          lazy[n] ^= v;
          propagate(n, ns, ne);
          return;
      }

      int mid = ns + ne >> 1;
      flip(l, r, v, n << 1, ns, mid);
      flip(l, r, v, n << 1 | 1, mid, ne);
      t[n] = t[n << 1] + t[n << 1 | 1];
  };

  function<long long(int, int, int, int, int)> query = [&](int l, int r, int n, int ns, int ne) {
    propagate(n, ns, ne);
    if (r <= ns || ne <= l) return 0LL;
    if (l <= ns && ne <= r) return t[n];
    int mid = ns + ne >> 1;
    return query(l, r, n << 1, ns, mid) + query(l, r, n << 1 | 1, mid, ne);
  };


  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > c) swap(b, c);
    if (a == 1) {
      cout << query(b - 1, c, 1, 0, N) << '\n';
    } else {
      flip(b - 1, c, 1, 1, 0, N);
    }
  }
}