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

  ll N;
  cin >> N;

  map<int, int> pos;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    pos[num] = i;
  }
  vl t(2 * N, 0);

  for (int i = N; i < 2 * N; ++i) {
    t[i] = 1;
  }
  for (int i = N - 1; i > 0; --i) {
    t[i] = t[i << 1] + t[i << 1 | 1];
  }

  auto sum = [&](int l, int r) {
    ll ret = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ret += t[l++];
      if (r & 1) ret += t[--r];
    }
    return ret;
  };
  auto update = [&](int p) {
    for (t[p += N] = 0; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
  };

  int l = 1;
  int r = N;

  for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
      // l 
      cout << sum(0, pos[l]) << '\n';
      update(pos[l]);
      ++l;
    } else {
      cout << sum(pos[r] + 1, N) << '\n';
      update(pos[r]);
      --r;
    }
  }
}