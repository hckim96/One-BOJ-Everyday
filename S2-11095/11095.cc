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

  int N;
  cin >> N;
  string line;
  getline(cin, line);

  map<string, vector<string> > adj;
  for (int i = 0; i < N; ++i) {
    getline(cin, line);
    stringstream ss(line);
    string tmp;
    string first = "";
    while (getline(ss, tmp, ' ')) {
      if (first == "") first = tmp;
      else {
        adj[first].push_back(tmp);
        adj[tmp].push_back(first);
      }
    }
  }

  string s, e;
  cin >> s >> e;

  vector<string> ans;
  ans.push_back(s);

  map<string, int> visited;
  bool found = false;
  function<void(string&)> f = [&](string& cur) {
    if (cur == e) {
      found = true;
      return;
    }

    for (auto& e: adj[cur]) {
      if (!visited[e]) {
        visited[e] = true;
        ans.push_back(e);
        f(e);
        if (found) return;
        ans.pop_back();
        visited[e] = false;
      }
    }
  };

  visited[s] = true;
  f(s);

  if (!found) {
    cout << "no route found\n";
  } else {
    for (auto e: ans) {
      cout << e << ' ';
    }
  }

  return 0;

}