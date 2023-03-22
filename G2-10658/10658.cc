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

  ll N, A, B;
  cin >> N >> A >> B;

  vector<pair<ll, string> > v;
  v.push_back({-1e11 - 1, "NS"});
  for (int i = 0; i < N; ++i) {
    string s;
    ll num;
    cin >> s >> num;
    v.push_back({num, s});
  }
  v.push_back({1e11 + 1, "NS"});
  sort(all(v));
  ll ans = 0;
  for (int i = 1; i < v.size() - 1; ++i) {
    if (v[i].second == "NS") continue;
    ll left = (v[i - 1].first + v[i].first) / 2 + ((v[i].first + v[i - 1].first) % 2 == 1);
    ll right = (v[i].first + v[i + 1].first) / 2 - (v[i].second == "S" && v[i + 1].second == "S" && (v[i].first + v[i + 1].first) % 2 == 0);
    if (right < A) continue;
    if (left > B) break;

    left = max(left, A);
    right = min(right, B);
    assert(right >= left);

    ans += right - left + 1;
  }
  cout << ans << '\n';

}