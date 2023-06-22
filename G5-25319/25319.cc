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

  int n, m, slen;
  cin >> n >> m >> slen;

  vector<vpi> v(26);

  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; ++j) {
      v[tmp[j] - 'a'].push_back({i, j});
    }
  }
  string s; cin >> s;
  vi cnt(26);
  each(e, s) cnt[e - 'a']++;

  int ansC = 1e9;

  each(e, s) ansC = min(ansC, (int)v[e - 'a'].size() / cnt[e - 'a']);


  string l = "";

  auto move = [&](pi& cur, pi& target) {
      int dr = target.first - cur.first;
      int dc = target.second - cur.second;

      char rc = (dr > 0) ? 'D' : 'U';
      char cc = (dc > 0) ? 'R' : 'L';

      dr = abs(dr);
      dc = abs(dc);

      rep(dr) l += rc;
      rep(dc) l += cc;
  };
  pi cur = {0, 0};

  for (int i = 0; i < ansC; ++i) {
    for (int j = 0; j < s.size(); ++j) {
      pi target;
      target = v[s[j] - 'a'].back();
      v[s[j] - 'a'].pop_back();
      move(cur, target);
      l += 'P';
      cur = target;
    }
  }


  pi tmp = {n - 1, m - 1};
  move(cur, tmp);

  cout << ansC << ' '  << l.size() << '\n';
  cout << l;
}