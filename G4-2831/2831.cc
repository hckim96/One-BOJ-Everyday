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

  vl mh, ms, wh, ws;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    if (num > 0) mh.push_back(num);
    else ms.push_back(-num);
  }
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    if (num > 0) wh.push_back(num);
    else ws.push_back(-num);
  }

  ll ans = 0;
  sort(all(mh));
  sort(all(ws));

  int l = 0;
  int r = 0;
  while (l < mh.size() && r < ws.size()) {
    if (mh[l] < ws[r]) {
      ++ans;
      l++;
      r++;
    } else {
      ++r;
    }
  }
  sort(all(ms));
  sort(all(wh));
  l = 0;
  r = 0;
  while (l < ms.size() && r < wh.size()) {
    if (ms[l] > wh[r]) {
      ++ans;
      l++;
      r++;
    } else {
      ++l;
    }
  }
  cout << ans << '\n';
}