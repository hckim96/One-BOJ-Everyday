#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N;
  cin >> N;
  vector<long long> v(N);
  for (auto& e: v) cin >> e;

  // idx, h
  stack<pair<int, long long> > st;
  st.push({N, 1e9 + 1});
  long long ans = 0;
  for (int i = N - 1; i >= 0; --i) {
    while (st.size() && st.top().second < v[i]) st.pop();

    ans += st.top().first - i - 1;
    st.push({i, v[i]});
  }
  cout << ans << '\n';
}