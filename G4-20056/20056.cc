#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, M, K;
  cin >> N >> M >> K;

  // r c m s d
  vector<vector<tuple<int, int, int, int> > > v(N, vector<tuple<int, int, int, int> > (N, {0, 0, 0, 0}));

  for (int i = 0; i < M; ++i) {
    int r, c, m, s, d;
    cin >> r >> c >> m >> s >> d;
    v[r - 1][c - 1] = {1, m, s, d};
  }

  int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
  int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
  while (K--) {

    vector<vector<tuple<int, int, int, int> > > nv(N, vector<tuple<int, int, int, int> > (N, {0, 0, 0, 0}));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (get<0>(v[i][j])) {
          //move
          auto [n, m, s, d] = v[i][j];
          if (n == 0) continue;

          if (n == 1) {
            int nr = i + dr[d] * s;
            int nc = j + dc[d] * s;
            nr = (nr % N + N) % N;
            nc = (nc % N + N) % N;

            auto& [nn, nm, ns, nd] = nv[nr][nc];

            nn += 1;
            nm += m;
            ns += s;

            if (nn >= 2 && nd <= 7) {
              if (nd % 2 == d % 2) {

              } else {
                nd = 9;
              }
            } else if (nn == 1) {
              nd = d;
            }
          } else {
            // n > 1
            if (m < 5) continue;
            // divide
            for (int k = 0; k < 4; ++k) {
              int nd_;
              if (d == 9) {
                nd_ = 2 * k + 1;
              } else {
                nd_ = 2 * k;
              }
              int nr = i + dr[nd_] * (s / n);
              int nc = j + dc[nd_] * (s / n);
              nr = (nr % N + N) % N;
              nc = (nc % N + N) % N;
              auto& [nn, nm, ns, nd] = nv[nr][nc];
              nn += 1;
              nm += m / 5;
              ns += s / n;
              if (nn >= 2 && nd <= 7) {
                if (nd % 2 == nd_ % 2) {

                } else {
                  nd = 9;
                }
              } else if (nn == 1) {
                nd = nd_;
              }
            }
          }
        }
      }
    }
    v = nv;
  }
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      auto [n, m, s, d] = v[i][j];
      if (n == 1) {
        ans += m;
      } else if (n > 1) {
        ans += (m / 5) * 4;
      }
    }
  }
  cout << ans << '\n';
}