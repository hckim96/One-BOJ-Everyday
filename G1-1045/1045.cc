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

  ll N, M;
  cin >> N >> M;
  vl p(N, -1);
  function<ll(int)> myFind = [&](ll cur){
    if (p[cur] == -1) return cur;
    return p[cur] = myFind(p[cur]);
  };

  auto myUnion = [&](int u, int v) {
    auto pu = myFind(u);
    auto pv = myFind(v);
    if (pu == pv) return false;
    p[pu] = pv;
    return true;
  };
  ll groupCnt = N;
  vl ans(N, 0);

  vector<pair<int,int> > remainder;

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = i; j < N; ++j) {
      if (s[j] == 'Y') {
        if (myUnion(i, j)) {
          M--;
          groupCnt--;
          ans[i]++;
          ans[j]++;


        } else {
          remainder.push_back({i, j});
        }
      }
    }
  }

  if (remainder.size() < M) {
    cout << -1;
    return 0;
  }
  
  for (int i = 0; i < M; ++i) {
    auto [u, v] = remainder[i];
    ans[u]++;
    ans[v]++;
    if (myUnion(u, v)) groupCnt--;
  }

  if (groupCnt == 1) {
    for (auto e: ans) {
      cout << e << ' ';
    }
  } else {
    cout << -1;
  }
}