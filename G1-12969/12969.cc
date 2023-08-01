#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> t;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
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

  int N, K;
  cin >> N >> K;

  string ans;
  ans.resize(N);

  string rans;
  vector<vector<vvi> > dp(N, vector<vvi> (N, vvi(N, vi(K + 1, -1))));
  function<int(int, int, int, int)> f = [&](int i, int a, int b, int k) {
    if (i == N) {
      if (k == K) {
        rans = ans;
        return 1;
      }
      else return -1;
    }

    if (rans != "") return 1;

    auto& ret = dp[i][a][b][k];
    if (ret != -1) return ret;

    ret = 0;
    ans[i] = 'A';
    ret |= f(i + 1, a + 1, b, k);
    ans[i] = 'B';
    ret |= f(i + 1, a, b + 1, k + a);
    ans[i] = 'C';
    ret |= f(i + 1, a, b, k + a + b);
  };

  f(0, 0, 0, 0);

  if (rans == "") cout << -1;
  else cout << rans;
}