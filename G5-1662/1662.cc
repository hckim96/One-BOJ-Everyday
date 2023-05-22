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

  string s;
  cin >> s;

  stack<pair<int, char> > st;
  each(e, s) {
    if (e == '(') {
      st.push({0, e});
    } else if (e == ')') {
      int cnt = 0;
      char last = 'x';
      while (st.top().second != '(') {
        last = st.top().second;
        cnt += st.top().first ? st.top().first : 1;
        st.pop();
      }
      // (
      st.pop();
      // multiply
      int total = cnt * (st.top().second - '0');
      st.pop();

      if (total == 0) continue;
      if (total == 1) {
        st.push({0, last});
      } else {
        st.push({total - 1, 'x'});
        st.push({0, last});
      }
    } else {
      st.push({0, e});
    }
  }

  int ans = 0;
  while (st.size()) {
    ans += st.top().first ? st.top().first : 1;
    st.pop();
  }
  cout << ans;
}