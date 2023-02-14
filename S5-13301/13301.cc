#include <bits/stdc++.h>

using namespace std;


#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  
  ll n;
  cin >> n;

  vector<vector<ll> > v(n + 1, vector<ll> (2, 0));
  v[1][0] = 1;
  v[1][1] = 1;
  for (int i = 2; i <= n; ++i) {
    v[i][0] = v[i - 1][1];
    v[i][1] = v[i - 1][0] + v[i - 1][1];
  }
  cout << 2 * (v[n][0] + v[n][1]) << '\n';
}
