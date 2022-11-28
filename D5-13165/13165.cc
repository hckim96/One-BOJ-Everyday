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

  ll N, L;
  cin >> N >> L;
  vvl A(N, vl(L));
  for (auto& e: A) for (auto& ee: e) cin >> ee;
  vvl x(N, vl(1, 0));
  std::random_device rd;
  std::mt19937 gen(rd());
  // [min, max]
  std::uniform_int_distribution<int> dis(0, 65535);
  for (auto& e: x) for (auto& ee: e) ee = dis(gen);

  auto check =[&](int c) {

    // c, c + N, c + 2 * N

    int cnt = 1;
    while (cnt--) {

      vvl tmp1(N, vl(1, 0));
      vvl tmp2(N, vl(1, 0));
      // B * x
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 1; ++j) {
          for (int k = c + N; k < c + 2 * N; ++k) {
            tmp1[i][j] += A[i][k] * x[k - c - N][j];
          }
        }
      }
      // A * 
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 1; ++j) {
          for (int k = c; k < c + N; ++k) {
            tmp2[i][j] += A[i][k] * tmp1[k - c][j];
          }
        }
      }

      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 1; ++j) {
          tmp1[i][j] = 0;
          for (int k = c + 2 * N; k < c + 3 * N; ++k) {
            tmp1[i][j] += A[i][k] * x[k - c - 2 * N][j];
          }
          if (tmp1[i][j] != tmp2[i][j]) return false;
        }
      }

    }
    return true;
  };

  ll ans = 0;
  for (int cc = 0; cc + 3 * N <= L; ++cc) {
    if (check(cc)) {
      ans += N * 3 * N;
      cc += 3 * N - 1;
    }
  }
  cout << ans << '\n';
}