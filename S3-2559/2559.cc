#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, K;
  cin >> N >> K;

  vector<int> v(N);
  for (auto& e: v) cin >> e;

  ll tmp = 0;
  for (int i = 0; i < K; ++i) {
    tmp += v[i];
  }
  ll ans = tmp;
  for (int i = K; i < N; ++i) {
    tmp -= v[i - K];
    tmp += v[i];
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
}