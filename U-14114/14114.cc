#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  long long N;
  cin >> N;
  cin.ignore();
  vector<string> v(N);
  for (long long i = 0; i < N; ++i) {
    getline(cin, v[i]);
  }
  long long ret;
  cin >> ret;

  pair<long long, long long> cur = {ret, ret + 1};
  for (long long i = N - 1; i >= 0; --i) {
      // A +
      // Z -
      // N *
      // I /
    long long x = v[i][v[i].size() - 1] - '0';

    switch (v[i][3]) {
      case 'A':
        cur = {cur.first - x, cur.second - x};
        break;
      case 'Z':
        cur = {cur.first + x, cur.second + x};
        break;
      case 'N':
        cur = {cur.first / x + (cur.first % x > 0), cur.second / x + (cur.second % x > 0)};
        break;
      case 'I':
        long long nf, ns;
        if (cur.first == 0) nf = -x + 1;
        else if (cur.first < 0) nf = cur.first * x - (x - 1);
        else nf = cur.first * x;
        if (cur.second == 0) ns = -x + 1;
        else if (cur.second < 0) ns = cur.second * x - (x - 1);
        else ns = cur.second * x;
        cur = {nf, ns};
        break;
    }
  }
  cout << cur.second - cur.first << '\n';
}