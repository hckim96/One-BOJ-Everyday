#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int n = 10;

  int cnt = 0;
  int answer = 0;
  while (n--) {
    int m, p;
    cin >> m >> p;

    cnt -= m;
    cnt += p;
    answer = max(answer, cnt);
  }
  cout << answer << '\n';
}