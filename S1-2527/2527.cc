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

  int TC = 4;
  while (TC--) {
    vector<pair<int, int> > r1(2);
    vector<pair<int, int> > r2(2);
    cin >> r1[0].first >> r1[0].second >> r1[1].first >> r1[1].second;
    cin >> r2[0].first >> r2[0].second >> r2[1].first >> r2[1].second;

    if (r1[0] > r2[0]) swap(r1, r2);
    char ans = ' ';
    if (r2[0].first == r1[0].first) {
      if (r2[0].second < r1[1].second) {
        ans = 'a';
      } else if (r2[0].second == r1[1].second) {
        ans = 'b';
      } else {
        ans = 'd';
      }
    } else if (r2[0].first < r1[1].first) {
      if (r2[0].second < r1[0].second) {
        if (r2[1].second < r1[0].second) {
          ans = 'd';
        } else if (r2[1].second == r1[0].second) {
          ans = 'b';
        } else {
          ans = 'a';
        }
      } else if (r2[0].second == r1[0].second) {
        ans = 'a';
      } else if (r2[0].second < r1[1].second) {
        ans = 'a';
      } else if (r2[0].second == r1[1].second) {
        ans = 'b';
      } else {
        ans = 'd';
      }
    } else if (r2[0].first == r1[1].first) {
      if (r2[0].second < r1[0].second) {
        if (r2[1].second < r1[0].second) {
          ans = 'd';
        } else if (r2[1].second == r1[0].second) {
          ans = 'c';
        } else {
          ans = 'b';
        }
      } else if (r2[0].second == r1[0].second) {
        ans = 'b';
      } else if (r2[0].second < r1[1].second) {
        ans = 'b';
      } else if (r2[0].second == r1[1].second) {
        ans = 'c';
      } else {
        ans = 'd';
      }
    } else {
      ans = 'd';
    }
    cout << ans << '\n';
  }
}