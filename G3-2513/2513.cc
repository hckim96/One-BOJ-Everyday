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

  ll N, K, S;
  cin >> N >> K >> S;
  vector<pair<ll, ll > > p;
  vector<pair<ll, ll > > m;

  for (int i = 0; i < N; ++i) {
    ll p_, cnt;
    cin >> p_ >> cnt;
    if (p_ >= S) {
      p.push_back({p_ - S, cnt});
    } else {
      m.push_back({S - p_, cnt});
    }
  }

  sort(rall(p));
  sort(rall(m));

  ll ans = 0;
  for (int i = 0; i < p.size(); ++i) {
    ll left = K;
    ans += p[i].second / K * p[i].first;
    if (p[i].second % K) ans += p[i].first;
    else continue;
    left -= p[i].second % K;
    if (left) {
      for (int j = i + 1; j < p.size(); ++j) {
        if (left == 0) break;
        ll tmp = min(left, p[j].second);
        p[j].second -= tmp;
        left -= tmp;
      }
    }
  }
  for (int i = 0; i < m.size(); ++i) {
    ll left = K;
    ans += m[i].second / K * m[i].first;
    if (m[i].second % K) ans += m[i].first;
    else continue;
    left -= m[i].second % K;
    if (left) {
      for (int j = i + 1; j < m.size(); ++j) {
        if (left == 0) break;
        ll tmp = min(left, m[j].second);
        m[j].second -= tmp;
        left -= tmp;
      }
    }
  }
  cout << ans * 2;
}