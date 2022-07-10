#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, M, K;
  cin >> N >> M >> K;

  vector<vector<long long> > dist(N + 1, vector<long long> (K + 1, 1e18));
  vector<vector<pair<long long, long long> > > edge(N + 1);

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    edge[a].push_back({b, c});
    edge[b].push_back({a, c});
  }

  priority_queue<tuple<long long, long long, long long>, vector<tuple<long long, long long, long long> >, greater<tuple<long long, long long, long long> > > pq;
  dist[1][0] = 0;
  pq.push({0, 1, 0});
  while (pq.size()) {
    auto [d, n, k] = pq.top();
    pq.pop();
    if (d > dist[n][k]) continue;
    for (auto [nn, nc]: edge[n]) {
      if (k < K) {
        if (dist[nn][k + 1] > d) {
          dist[nn][k + 1] = d;
          pq.push({dist[nn][k + 1], nn, k + 1});
        }
      }
      if (dist[nn][k] > nc + d) {
          dist[nn][k] = nc + d;
          pq.push({dist[nn][k], nn, k});
      }
    }
  }

  long long ans = 1e18;
  for (int k = 0; k <= K; ++k) {
    ans = min(dist[N][k], ans);
  }
  cout << ans << '\n';
}