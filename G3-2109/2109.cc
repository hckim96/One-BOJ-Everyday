#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int N;
  cin >> N;
  if (N == 0)  {
    cout << 0 << '\n';
    return 0;
  }
  vector<pair<int, int> > v(N);
  for (auto& e: v) cin >> e.second >> e.first;
  sort(rall(v));

  int idx = 0;

  priority_queue<int> pq;

  int day = v[idx].first + 1;
  int ans = 0;

  while (day-- > 1) {

    while (idx < v.size()) {
      if (v[idx].first >= day) {
        pq.push(v[idx].second);
        ++idx;
      } else {
        break;
      }
    }

    if (pq.size()) {
      ans += pq.top();
      pq.pop();
    }
  }

  cout << ans << '\n';
}