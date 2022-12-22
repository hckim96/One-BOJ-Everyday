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

  ll N, M, K;
  cin >> N >> M >> K;

  if (!(N == 1 && M == 1)) {
    assert(N != 1 && M != 1);
  }
  queue<pair<ll, ll> > q;
  q.push({abs(N - M), N * M});
  ll ans = 0;
  vl nextds, curds;
  while (q.size()) {
    ll cnt = q.size();
    ll next = q.front().second - 1;
    vl tmpds;
    for (ll i = 1; i * i <= next; ++i) {
      if ((next) % i == 0) tmpds.push_back(abs(i - (next) / i));
    }
    swap(nextds, tmpds);
    set<ll> sett;
    while (cnt--) {
      auto [d, cur] = q.front();
      q.pop();

      ans = max(ans, N * M - cur);

      if (cur == 1) {
        cout << ans << '\n';
        return 0;
      }

      if (curds.size() == 1) {
        ans = N*M - 1;
        cout << ans << '\n';
        return 0;
      }
      auto it1 = nextds.begin();
      auto it2 = nextds.end();
      for (auto it = it1; it != it2; ++it) {
        if (abs(*it - abs(N - M)) <= K) {
          if (!sett.count(*it)) {
            q.push({*it, cur - 1});
            sett.insert(*it);
          }
        }
      }
    }
    swap(nextds, curds);
  }

  cout << ans << '\n';
}
