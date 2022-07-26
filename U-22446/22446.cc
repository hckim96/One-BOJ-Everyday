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

  int N;
  cin >> N;

  vector<vector<int> > adj(N);
  vector<int> indegree(N, 0);
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    indegree[b]++;
  }

  auto ROOT = min_element(all(indegree)) - indegree.begin();

  ll MOD = 1e9 + 7;
  vector<vector<vector<ll> > > dp2(N + 2, vector<vector<ll> > (N + 2, vector<ll> (N + 2, 0)));
  dp2[0][0][0] = 1;
  for (int i = 1; i <= N; ++i) {
    dp2[i][0][i] = dp2[0][i][i] = 1;
  }
  for (int c = 1; c <= N; ++c) {
    for (int a = 1; a <= N; ++a) {
      for (int b = 1; b <= N; ++b) {
        dp2[a][b][c] = dp2[a - 1][b - 1][c - 1] + dp2[a - 1][b][c - 1] + dp2[a][b - 1][c - 1];
        dp2[a][b][c] %= MOD;
      }
    }
  }

  vector<vector<ll> > dp1(N + 2, vector<ll> (N + 2, 0));
  vector<int> subtreeSize(N, 1);
  function<void(int)> ff = [&](int cur) {
    for (auto e: adj[cur]) {
      ff(e);
      subtreeSize[cur] += subtreeSize[e];
    }

    vector<ll> tmp(N + 2, 0);
    tmp[0] = 1;
    for (auto e: adj[cur]) {
      vector<ll> ttmp(N + 2, 0);
      for (int a = 0; a <= subtreeSize[cur]; ++a) {
        if (tmp[a] == 0) continue;
        for (int b = 0; b <= subtreeSize[cur]; ++b) {
          if (dp1[e][b] == 0) continue;
          for (int c = 0; c <= subtreeSize[cur]; ++c) {
            if (dp2[a][b][c] == 0) continue;
            ttmp[c] += tmp[a] * dp1[e][b] % MOD * dp2[a][b][c] % MOD;
            ttmp[c] %= MOD;
          }
        }
      }
      swap(ttmp, tmp);
    }

    for (int c = 0; c <= subtreeSize[cur]; ++c) {
      dp1[cur][c + 1] = tmp[c];
    }
  };

  ff(ROOT);

  ll ans = 0;
  for (int i = 0; i <= N; ++i) {
    ans += dp1[ROOT][i];
    ans %= MOD;
  }
  cout << ans << '\n';
}