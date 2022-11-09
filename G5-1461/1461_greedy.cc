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

  vector<long long> ap, am;
  long long maxabs = 0;
  for (int i = 0; i < N; ++i) {
    long long e;
    cin >> e;
    if (e > 0) ap.push_back(e);
    else am.push_back(e);
    maxabs = max(maxabs, abs(e));
  }

  sort(all(ap), greater<>());
  sort(all(am));

  long long ans = 0;
  for (int i = 0; i < ap.size();) {
    int j = i + M - 1;
    if (j >= ap.size()) j = ap.size() - 1;
    ans += abs(ap[j] - ap[i]) + abs(ap[i]) + abs(ap[j]);
    i = j + 1;
  }
  for (int i = 0; i < am.size();) {
    int j = i + M - 1;
    if (j >= am.size()) j = am.size() - 1;
    ans += abs(am[j] - am[i]) + abs(am[i]) + abs(am[j]);
    i = j + 1;
  }

  cout << ans -  maxabs << '\n';
}