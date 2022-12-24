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

  string line;
  getline(cin, line);

  auto sit = line.end();
  bool intag = false;
  for (auto it = line.begin(); it != line.end(); ++it) {
    if (intag) {
      if (*it == '>') {
        intag = false;
      }
    } else {
      if (*it == '<') {
        if (sit != line.end()) {
          reverse(sit, it);
        }
        sit = line.end();
        intag = true;
      } else if (*it == ' ') {
        if (sit != line.end()) {
          reverse(sit, it);
        }
        sit = line.end();
      } else {
        if (sit == line.end()) sit = it;

        if (it + 1 == line.end()) {
          if (sit != line.end()) {
            reverse(sit, it + 1);
          }
        }
      }
    }
  }

  cout << line << '\n';
}