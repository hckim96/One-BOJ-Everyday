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
string add36(string& s1, string& s2) {
    string ret(max(int(s1.size()), int(s2.size())), '0');
    int up = 0;
    for (int i = 0; i < ret.size(); ++i) {
      int tmp = up;
      up = 0;
      int l = s1.size() - 1 - i;
      int r = s2.size() - 1 - i;
      if (l >= 0) {
        if (s1[l] <= '9') tmp += s1[l] - '0';
        else tmp += 10 + s1[l] - 'A';
      }
      if (r >= 0) {
        if (s2[r] <= '9') tmp += s2[r] - '0';
        else tmp += 10 + s2[r] - 'A';
      }

      up = tmp / 36;
      tmp %= 36;
      if (tmp < 10) {
        ret[ret.size() - 1 - i] = '0' + tmp;
      } else {
        ret[ret.size() - 1 - i] = 'A' + (tmp - 10);
      }
    }
    if (up) ret = "1" + ret;
    return ret;
  };
struct cmp {
  bool operator()(pair<string, char>& p1, pair<string, char>& p2) {
    // true increasement
    string diff1 = "0";
    string diff2 = "0";
    int cnt1, cnt2;
    if (p1.second <= '9') cnt1 = p1.second - '0';
    else cnt1 = p1.second - 'A' + 10;
    if (p2.second <= '9') cnt2 = p2.second - '0';
    else cnt2 = p2.second - 'A' + 10;
    cnt1 = 35 - cnt1;
    cnt2 = 35 - cnt2;

    while (cnt1--) diff1 = add36(diff1, p1.first);
    while (cnt2--) diff2 = add36(diff2, p2.first);


    if (diff1.size() == diff2.size()) {
      int i = 0;
      while (i < diff1.size()) {
        if (diff1[i] < diff2[i]) return true;
        else if (diff1[i] > diff2[i]) return false;
        ++i;
      }
      return true;
    }
    
    
    return diff1.size() < diff2.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  ll N;
  cin >> N;

  vector<string> v(N);
  map<char, string> cnt;
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
    string post = "";
    for (int j = v[i].size() - 1; j >= 0; --j) {
      auto tmp = "1" + post;
      cnt[v[i][j]] = add36(cnt[v[i][j]], tmp);
      post += "0";
    }
  }

  priority_queue<pair<string, char>, vector<pair<string, char> >, cmp > pq;
  for (auto e: cnt) {
    pq.push({e.second, e.first});
  }

  int K;
  cin >> K;
  while (pq.size() && K--) {
    auto [s1, c] = pq.top();
    pq.pop();
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        if (v[i][j] == c) v[i][j] = 'Z';
      }
    }
  }

  string ans = "0";
  for (int i = 0; i < v.size(); ++i) {
    ans = add36(ans, v[i]);
  }

  cout << ans << '\n';
  return 0;
}