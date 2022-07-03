#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int A, B, C;

  cin >> A >> B >> C;
  vector<vector<vector<int> > > visited(201, vector<vector<int> > (201, vector<int> (201, 0)));

  set<int> ans;

  visited[0][0][C] = true;
  queue<tuple<int, int, int> > q;
  q.push({0, 0, C});
  while (q.size()) {
    auto [a, b, c] = q.front();
    if (a == 0)
    ans.insert(c);
    q.pop();
    int na, nb, nc;
    if (a) {
      // a -> b
      if (B - b >= a) {
        nb = a + b;
        na = 0;
        nc = c;
      } else {
        na = a - B + b;
        nb = B;
        nc = c;
      }
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        q.push({na, nb, nc});
      }
      // a -> c
      if (C - c >= a) {
        nc = a + c;
        na = 0;
        nb = b;
      } else {
        na = a - C + c;
        nc = C;
        nb = b;
      }
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        q.push({na, nb, nc});
      }
    }

    if (b) {
      // b -> a
      if (A - a >= b) {
        na = b + a;
        nb = 0;
        nc = c;
      } else {
        nb = b - A + a;
        na = A;
        nc = c;
      }
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        q.push({na, nb, nc});
      }
      // b -> c
      if (C - c >= b) {
        nc = b + c;
        nb = 0;
        na = a;
      } else {
        nb = b - C + c;
        nc = C;
        na = a;
      }
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        q.push({na, nb, nc});
      }
    }

    if (c) {
      // c -> a
      if (A - a >= c) {
        na = a + c;
        nc = 0;
        nb = b;
      } else {
        nc = c - A + a;
        na = A;
        nb = b;
      }
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        q.push({na, nb, nc});
      }
      // c -> b
      if (B - b >= c) {
        nb = b + c;
        nc = 0;
        na = a;
      } else {
        nc = c - B + b;
        nb = B;
        na = a;
      }
      if (!visited[na][nb][nc]) {
        visited[na][nb][nc] = true;
        q.push({na, nb, nc});
      }

    }

  }

  for (auto e: ans) {
    cout << e << ' ';
  }

}