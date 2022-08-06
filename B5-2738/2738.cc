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

  int N, M;
  cin >> N >> M;
  vector<vector<int> > a(N, vector<int> (M));
  vector<vector<int> > b(N, vector<int> (M));
  for (auto& e: a) for (auto& ee: e) cin >> ee;
  for (auto& e: b) for (auto& ee: e) cin >> ee;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << a[i][j] + b[i][j] << ' ';
    }
    cout << '\n';
  }
}