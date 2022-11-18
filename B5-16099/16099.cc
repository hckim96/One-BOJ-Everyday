#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

  int TC; cin >> TC;
  while (TC--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * b < c * d) {
      cout << "Eurecom\n";
    } else if (a * b > c * d){
      cout << "TelecomParisTech\n";
    } else {
      cout << "Tie\n";
    }
  }
}