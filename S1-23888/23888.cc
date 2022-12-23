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

  
  ll a, d;
  cin >> a >> d;
  ll q;
  cin >> q;
  while (q--) {
    ll t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      // sum
      cout << (2 * a + (l + r - 2) * d) * (r - l + 1) / 2 << '\n';

    } else {
      // 
      if (l == r) cout << a + (l - 1) * d << '\n';
      else cout << gcd(a, d) << '\n';
    }
  }
}