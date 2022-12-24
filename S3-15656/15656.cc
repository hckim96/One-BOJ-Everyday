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

  int N, M;
  cin >> N >> M;
  vl a(N);
  for (auto& e: a) cin >> e;
  sort(all(a));
  // N 개 중 M 개 중복 선택 수열
  function<void(vector<int>&)> f = [&](vector<int>& selected) {
    if (selected.size() == M) {
      for (auto e: selected) {
        cout << e << ' ';
      }
        cout << '\n';
      return;
    }

    for (int i = 0; i < N; ++i) {
      selected.push_back(a[i]);
      f(selected);
      selected.pop_back();
    }
  };

  vector<int> selected;
  f(selected);

}