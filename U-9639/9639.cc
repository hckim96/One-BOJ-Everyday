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

  int TC; cin >> TC;
  while (TC--) {
    ll N, M;
    cin >> N >> M;

    vector<vector<ll> > v(N + 1, vector<ll> (M + 1, 0));
    vector<vector<ll> > pv(N + 1, vector<ll> (M + 1, 0));
    for (ll i = 1; i <= N; ++i) {
      for (ll j = 1; j <= M; ++j) {
        cin >> v[i][j];
        pv[i][j] = v[i][j] + pv[i - 1][j] + pv[i][j - 1] - pv[i - 1][j - 1];
      }
    }

    ll ans = -1e18;
    for (ll i = 1; i <= N; ++i) {
      for (ll j = 1; j <= M; ++j) {
        ans = max(ans, pv[N][M] - pv[i - 1][M] - pv[N][j - 1] + pv[i - 1][j - 1]);
      }
    }
    cout << ans << '\n';
  }
}