#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  

  int tc; cin >> tc;
  while (tc--) {
    int N;
    cin >> N;
    vector<vector<int> > adj(N + 1);
    vector<int> ind(N + 1, 0);
    vector<int> p(N + 1, -1);

    int tmp = N - 1;
    while (tmp--) {
      int pp, c;
      cin >> pp >> c;
      adj[pp].push_back(c);
      p[c] = pp;
      ++ind[c];
    }

    int root = min_element(ind.begin() + 1, ind.end()) - ind.begin();
    vector<int> d(N + 1, 0);

    queue<int> q;
    q.push(root);
    while (q.size()) {
      auto f = q.front();
      q.pop();
      for (auto e : adj[f]) {
        d[e] = d[f] + 1;
        q.push(e);
      }
    }

    int a, b;
    cin >> a >> b;
    if (d[a] < d[b]) {
      swap(a, b);
    }

    while (d[a] != d[b]) {
      a = p[a];
    }

    while (a != b) {
      a = p[a];
      b = p[b];
    }
    cout << a << '\n';
  }
}