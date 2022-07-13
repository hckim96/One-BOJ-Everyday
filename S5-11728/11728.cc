#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int N, M;
  cin >> N >> M;

  vector<int> v(N + M);
  for (auto& e: v) cin >> e;
  sort(all(v));
  for (auto e: v) cout << e << ' ';
  cout << '\n';
}