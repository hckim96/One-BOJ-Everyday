#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tlll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<int>> vvi;
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

  ll k;
  cin >> k;

  vector<pair<int, int> >  y;
  vector<pair<int, int> >  x;
  FOR (i, 0, 6) {
    int a, b;
    cin >> a >> b;
    if (a <= 2) {
      x.push_back({a, b});
    } else {
      y.push_back({a, b});
    }
  }
  FOR (i, 0, 3) {
    y.push_back(y[i]);
    x.push_back(x[i]);
  }
  pair<int, int>  ymax = {0, 0};
  pair<int, int>  xmax = {0, 0};
  int ymaxidx = 0;
  int xmaxidx = 0;

  FOR (i, 0, 3) {
    if (y[i].second > ymax.second) {
      ymax = y[i];
      ymaxidx = i;
    }
  }
  FOR (i, 0, 3) {
    if (x[i].second > xmax.second) {
      xmax = x[i];
      xmaxidx = i;
    }
  }

  ll y2;
  ll x2;
  int dx = 1;
  int dy = 1;
  if (xmax.first == 1) {
    if (ymax.first == 4) {
      dx = 2;
      dy = 1;
    } else {
      dx = 1;
      dy = 2;
    }
  } else {
    // 2
    if (ymax.first == 4) {
      dx = 1;
      dy = 2;
    } else {
      dx = 2;
      dy = 1;
    }
  }
  cout << k * (ymax.second * xmax.second - y[ymaxidx + dy].second * x[xmaxidx + dx].second);
}