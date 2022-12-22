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

  int N, K;
  cin >> N >> K;

  vector<tuple<int, int, int> > v(N);
  set<int> s1, s2, s3;
  for (int i = 0; i < N; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[i] = {a, b, c};
    s1.insert(a);
    s2.insert(b);
    s3.insert(c);
  }

  int ans = 1e8;
  for (auto e1: s1) {
    for (auto e2: s2) {
      for (auto e3: s3) {

        ll cnt = 0;
        for (int i = 0; i < N; ++i) {
          auto [a, b, c] = v[i];
          if (e1 >= a && e2 >= b && e3 >= c) ++cnt;
        }


        if (cnt >= K) {
          ans = min(ans, e1 + e2 + e3);
        }
      }
    }
  }

  cout << ans << '\n';
}