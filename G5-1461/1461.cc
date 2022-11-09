#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N, M;
  cin >> N >> M;

  vector<int> a(N);
  for (auto& e: a) cin >> e;

  sort(all(a));

  vector<vector<long long> > dp(N, vector<long long> (N, -1));
  function<long long(int, int)> f = [&](int s, int e) {
    if (dp[s][e] != -1) return dp[s][e];
    if (s == e) return dp[s][e] = 2 * abs(a[e]);

    long long tmp = 2e18;
    if (e - s + 1 <= M) tmp = a[e] - a[s] + abs(a[s]) + abs(a[e]);

    for (int i = 0; i < min(M, e - s); ++i) {
      tmp = min (tmp, a[s + i] - a[s] + abs(a[s + i]) + abs(a[s]) + f(s + i + 1, e));
    }
    return dp[s][e] = tmp;
  };

  cout << f(0, N - 1) - max(abs(a.front()), abs(a.back())) << '\n';
}