#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;

    vector<tuple<int, int, int> > p(3 * N);
    for (int i = 0; i < 3 * N; ++i) {
      int a, b;
      cin >> a >> b;
      p[i] = {a, b, i + 1};
    }
    sort(all(p));
    vector<int> visited(3 * N, 0);
    for (int i = 0; i < N; ++i) {
      vector<tuple<int, int, int> > pp;

      int idx = 0;
      while (pp.size() != 3) {
        if (visited[idx]) {
          ++idx;
          continue;
        }

        auto [a, b, c] = p[idx];
        bool ok = true;
        for (auto [aa, bb, cc]: pp) {
          if (a == aa && b == bb) {
            ok = false;
            break;
          }
        }
        if (ok) {
          pp.push_back(p[idx]);
          visited[idx] = true;
        }
        ++idx;
      }
      for (auto [a, b, c]: pp) {
        cout << c << ' ';
      }
      cout << '\n';
    }
  }
}