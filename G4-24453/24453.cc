#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N, M;
  cin >> N >> M;

  vector<int> l, r;
  vector<ll> perr(N + 2, 0);
  int prev = 0;
  for (int i = 0; i <= M; ++i) {
    int cur;
    if (i == M) cur = N + 1;
    else cin >> cur;

    perr[cur] = 1;

    if (prev + 1 < cur) l.push_back(prev + 1), r.push_back(cur);
    prev = cur;
  }

  for (int i = 1; i < N + 2; ++i) perr[i] += perr[i - 1];

  ll X, Y;
  cin >> X >> Y;

  ll ans = 0;
  for (int i = 0; i < l.size(); ++i) {
    auto it = lower_bound(all(r), l[i] + X);
    if (it != r.end()) {
      ans = max(ans, M - max(Y, perr[*it - 1] - perr[l[i] - 1]));
    }

    if (r[i] - 1 >= X && perr[r[i] - 1] >= Y) {
      ans = max(ans, M - max(Y, perr[r[i] - 1] - perr[r[i] - X - 1]));
    }
    if (l[i] + X - 1 <= N && perr[N] - perr[l[i] - 1] >= Y) {
      ans = max(ans, M - max(Y, perr[l[i] + X - 1] - perr[l[i] - 1]));
    }
  }
  cout << ans << '\n';
}