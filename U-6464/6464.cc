#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  cout << "Turn Score\n";
  int tc = 1;
  while (true) {
    vector<pair<long double, long double> > v(8);
    for (int i = 0; i < 8; ++i) {
      if (!(cin >> v[i].first >> v[i].second)) goto u;
    }

    int ans = 0;
    pair<long double, long double> p = {0, 0};

    auto distsqr = [&](pair<long double, long double> p1, pair<long double, long double> p2) {
      return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
    };

    for (int i = 0; i < 8; i += 2) {
      auto a = v[i];
      auto b = v[i + 1];
      pair<long double, long double> b_ = {2.0L * a.first - b.first, 2.0L * a.second - b.second};

      auto ap = distsqr(a, p);
      auto bp = distsqr(b, p);
      auto b_p = distsqr(b_, p);

      if (ap < 9 * 9 && bp <= b_p) {
        ans += 5;
        continue;
      }

      if (ap >= 9 * 9 && ap <= 11 * 11 && bp <= b_p) {
        ans += 2;
        continue;
      }

      if (bp <= (5.0L * sqrtl(2) + 1) * (5.0L * sqrtl(2) + 1)) {
        ans += 1;
        continue;
      }

      continue;
    }

    string sp1;
    if (tc < 10) {
      sp1 = "    ";
    } else if (tc < 100) {
      sp1 = "   ";
    } else {
      sp1 = "  ";
    }
    cout << tc++ << sp1 << ans << (ans < 10 ? " " : "") << '\n';
  }
  u:;
}