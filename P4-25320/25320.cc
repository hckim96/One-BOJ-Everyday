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

  int n, m;
  cin >> n >> m;

  vector<pair<string, int> > v(m);
  set<int> st2;

  set<int> st;

  for (int i = 1; i <= 2 * n; ++i) st.insert(i);

  for (int i = 0; i < m; ++i) {
    string tmp;
    cin >> v[i].first >> tmp >> v[i].second;
    st.erase(v[i].second);
    st2.insert(v[i].second);
  }

  st2.insert(1e9);

  v.push_back({"Z", -1});

  vector<vector<pair<string, int> > > ans(m);
  for (int i = 0; i < m; ++i) {
    int parity = (v[i].first == v[i + 1].first);

    auto it = st.upper_bound(v[i].second);
    if (i != m - 1 && parity && it == st.end()) {
      cout << "NO\n";
      return 0;
    }

    int cnt = 0;
    string cur = (v[i].first == "A") ? "B" : "A";
    
    while (it != st.end() && *it < ( v[i].second == *st2.begin() ? *(next(st2.begin())) : *st2.begin())) {
      ++cnt;
      ans[i].push_back({cur, *it});
      cur = (cur == "A") ? "B" : "A";
      int tmp = *it;
      it++;
      st.erase(tmp);
    }
    st2.erase(v[i].second);

    if (ans[i].size() % 2 != parity) {
      if (st.size() && it == st.end()) {
        cout << "NO\n";
        return 0;
      }
      if (it != st.end()) {
        ans[i].push_back({cur, *it});
        st.erase(it);
      }
    }
  }

  if (st.size()) {
    cout << "NO\n";
    return 0;
  }

  if (ans.back().size()) {
    if (ans.back().back().first != "B") {
      cout << "NO\n";
      return 0;
    }
  } else {
    if (v[m - 1].first != "B") {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for (int i = 0; i < m; ++i) {
    cout << v[i].first << " BLOCK " << v[i].second << '\n';
    each(e, ans[i]) {
      cout << e.first << " CHAIN " << e.second << '\n';
    }
  }
}