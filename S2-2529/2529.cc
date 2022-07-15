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
  vector<int> v(10, 0);
  vector<int> visited(11, 0);
  vector<char> op(N);
  for (auto& e: op) cin >> e;

  vector<int> maxv(10, 0);
  vector<int> minv(10, 1e9);
  function<void(int, int)> f = [&](int cur, int done) {
      if (done == 10) {
        // check
        for (int i = 0; i < op.size(); ++i) {
          if (op[i] == '<' && v[i] > v[i + 1]) {
            return;
          } 

          if (op[i] == '>' && v[i] < v[i + 1]) {
            return;
          }
        }
        maxv = max(maxv, v);
        minv = min(minv, v);
        return;
      }

      for (int i = 0; i < 10; ++i) {
        if (visited[i]) continue;
        v[cur] = i;
        visited[i] = true;
        f(cur + 1, done + 1);
        visited[i] = false;
      }
  };

  f(0, 0);

  for (int i = 0; i < op.size() + 1; ++i) {
    cout << maxv[i];
  }
  cout << '\n';
  for (int i = 0; i < op.size() + 1; ++i) {
    cout << minv[i];
  }
  cout << '\n';
}