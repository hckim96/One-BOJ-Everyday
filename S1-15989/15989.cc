#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  vector<ll> dp(10001, 0);
  dp[0] = 1;
  for (int i = 1; i <= 3; ++i) {
    for (int j = i; j < dp.size(); ++j) {
      dp[j] += dp[j - i];
    }
  }
  int TC; cin >> TC;
  while (TC--) {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
  }
}