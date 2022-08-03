#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  vector<int> cnt(31, 0);
  for (int i = 0; i < 28; ++i) {
    int num;
    cin >> num;
    cnt[num]++;
  }

  for (int i = 1; i <= 30; ++i) {
    if (!cnt[i]) {
      cout << i << '\n';
    }
  }
}