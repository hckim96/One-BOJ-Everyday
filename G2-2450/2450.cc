#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N;
  cin >> N;
  vl a(N);
  vl cnt(4, 0);
  for (auto& e: a) {
    cin >> e;
    cnt[e]++;
  }

  vl vis(4, 0);
  vl ord;
  auto cal = [&]() {
    vl arranged(N);
    int idx = 0;
    for (auto e: ord) {
      for (int i = 0; i < cnt[e]; ++i) {
        arranged[idx++] = e;
      }
    }
    vvl posCnt(4, vl(4, 0));
    for (int i = 0; i < N; ++i) {
      posCnt[a[i]][arranged[i]]++;
    }

    return posCnt[1][2] + posCnt[1][3] + max(posCnt[2][3], posCnt[3][2]);
  };
  ll ans = 2e9;
  function<void(int)> f = [&](int cnt) {
    if (cnt == 3) {
      ans = min(ans, cal());
      return;
    }

    for (int i = 1; i <= 3; ++i) {
      if (vis[i]) continue;
      vis[i] = true;
      ord.push_back(i);
      f(cnt + 1);
      ord.pop_back();
      vis[i] = false;
    }
  };

  f(0);
  cout << ans << '\n';
}