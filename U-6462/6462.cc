#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);


  int tidx = 0;
  while (true) {
    vector<vector<int> > cost(21, vector<int> (21, 1e9));
    for (int i = 1; i <= 19; ++i) {
      int n;
      if (!(cin >> n)) goto u;
      while (n--) {
        int j;
        cin >> j;
        cost[i][j] = cost[j][i] = 1;
      }
    }

    for (int k = 1; k <= 20; ++k) {
      for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 20; ++j) {
          cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
      }
    }

    cout << "Test Set #" << ++tidx << '\n';
    int N;
    cin >> N;
    while (N--) {
      int a, b;
      cin >> a >> b;
      cout << (a < 10 ? " ": "") << a << " to" << (b < 10 ? "  " : " ") <<  b << ": " << cost[a][b] << '\n';
    }
    cout << '\n';
  }
  u:;
}