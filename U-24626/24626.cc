#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int TC; cin >> TC;

  vector<vector<long double> > v(4, vector<long double> (360));

  for (int i = 0; i < 360; ++i) {
    v[1][i] = i;
    v[2][i] = M_PI / 180 * i;
    v[3][i] = 400.0L / 360 * i;
  }
  while (TC--) {
    long double x;
    cin >> x;

    vector<pair<int, int> > ans;

    for (int i = 1; i <= 3; ++i) {
      for (int j = 0; j < 360; ++j) {
        if (abs(v[i][j] - x) < 1e-6) {
          ans.push_back({j, i});
          break;
        }
      }
    }

    if (ans.size() == 1) {
      cout << ans[0].first << ' ' << ans[0].second << '\n';
    } else {
      cout << "-1\n";
    }
  }
}