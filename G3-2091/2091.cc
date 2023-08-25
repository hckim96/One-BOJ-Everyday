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
typedef tuple<ll, ll, ll> tl;
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

  vi coinVal = {1, 5, 10, 25};

  int X;
  cin >> X;
  vi coinNum(4);
  each(e, coinNum) cin >> e;

  vvi dp(X + 1, vi(5, -1));
  for (int i = 0; i < 5; ++i) dp[0][i] = 0;


  for (int x = 1; x <= X; ++x) {
    for (int i = 0; i < 4; ++i) {
      if (dp[x][i] == -1) dp[x][i] = 0;
      if (x - coinVal[i] < 0) continue;
      if (coinNum[i] <= dp[x - coinVal[i]][i]) continue;
      if (dp[x - coinVal[i]][4] <= dp[x][4]) continue;

      dp[x] = dp[x - coinVal[i]];
      dp[x][i]++;
      dp[x][4]++;
    }
  }

  for (int i = 0; i < 4; ++i) cout << dp[X][i] << ' ';
}