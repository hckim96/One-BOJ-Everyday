#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N;
  ld lat, lon, h;

  auto getVec = [&](ld lat, ld lon) {
    auto clat = cosl(lat * M_PI / 180);
    auto slat = sinl(lat * M_PI / 180);
    auto clon = cosl(lon * M_PI / 180);
    auto slon = sinl(lon * M_PI / 180);
    return tuple<ld, ld, ld> {clat * clon, clat * slon, slat};
  };

  auto getCos = [&](tuple<ld, ld, ld> t1, tuple<ld, ld, ld> t2) {
    auto [x1, y1, z1] = t1;
    auto [x2, y2, z2] = t2;
    return x1 * x2 + y1 * y2 + z1 * z2;
  };
  int tidx = 0;
  while (cin >> N >> lat >> lon >> h && N) {
    cout << "Test case " << ++tidx << ":\n";
    auto v1 = getVec(lat, lon);
    for (int i = 0; i < N; ++i) {
      string s;
      ld lat1, lon1;
      cin >> s >> lat1 >> lon1;
      auto v2 = getVec(lat1, lon1);
      if (getCos(v1, v2) <= 0) {
        continue;
      }
      auto x = (1.0L / getCos(v1, v2) - 1) * 6378;
      if (x <= h) {
        cout << s << '\n';
      }
    }
    cout << '\n';
  }
}