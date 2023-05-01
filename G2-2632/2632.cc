#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int x;
  cin >> x;

  int m, n;
  cin >> m >> n;

  vi a(2 * m), b(2 * n);
  vi pa(2 * m), pb(2 * n);

  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    a[i + m] = a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    b[i + n] = b[i];
  }

  for (int i = 0; i < 2 * m; ++i) {
    pa[i] = a[i];
    if (i) pa[i] += pa[i - 1];
  }
  for (int i = 0; i < 2 * n; ++i) {
    pb[i] = b[i];
    if (i) pb[i] += pb[i - 1];
  }

  map<int, int> m1, m2;

  for (int i = 0; i < m; ++i) {
    for (int j = i; j < i + m - 1; ++j) {
      int sum = 0;
      sum += pa[j];
      if (i) sum -= pa[i - 1];
      m1[sum]++;
    }
  }
  m1[pa[m - 1]]++;

  for (int i = 0; i < n; ++i) {
    for (int j = i; j < i + n - 1; ++j) {
      int sum = 0;
      sum += pb[j];
      if (i) sum -= pb[i - 1];
      m2[sum]++;
    }
  }
  m2[pb[n - 1]]++;


  int ret = m1[x] + m2[x];
  for (auto e: m1) {
    ret += e.second * m2[x - e.first];
  }
  cout << ret;
}