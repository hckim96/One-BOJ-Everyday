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
vector<vector<long long> > operator *(vector<vector<long long> > v1, vector<vector<long long> > v2) {
    vector<vector<long long> > ret(v1.size(), vector<long long> (v2[0].size(), 0));
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[0].size(); ++j) {
            for (int k = 0; k < v1[0].size(); ++k) {
                ret[i][j] += v1[i][k] * v2[k][j];
                // ret[i][j] %= MOD;
            }
        }
    }
    return ret;
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
  vector<vvl> A(3, vvl(N, vl(N, 0)));
  for (auto& e: A) for (auto& ee: e) for (auto& eee: ee) cin >> eee;
  vvl ans(3, vl(3, 0));
  vvl x(N, vl(1, 0));
  std::random_device rd;
  std::mt19937 gen(rd());
  // [min, max]
  std::uniform_int_distribution<int> dis(0, 1);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (i == j) continue;
      for (int k = 0; k < 3; ++k) {
        if (i == k) continue;
        if (j == k) continue;
        if (ans[i][0] && ans[j][1] && ans[k][2]) continue;

        int cnt = 5;
        while (cnt--) {
          for (auto& e: x) for (auto& ee: e) ee = dis(gen);
          auto tmp2 = A[i] * (A[j] * x);
          auto tmp3 = A[k] * x;
          for (int r = 0; r < tmp2.size(); ++r) {
            if (tmp2[r] != tmp3[r]) goto next;
          }
        }
        ans[i][0] = ans[j][1] = ans[k][2] = true;

        next:;
      }
    }
  }


  for (int i = 0; i < 3; ++i) {
    ll sum = 0;
    for (int j = 0; j < 3; ++j) {
      sum += ans[i][j] * (1 << j);
    }
    cout << sum << '\n';
  }
}