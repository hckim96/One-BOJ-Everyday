#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);

  int m = 1e9;
  int M = -1e9;

  int N;
  cin >> N;

  queue<pair<int, int> > q;
  
  auto countOdd = [&](int n) {
    int ret = 0;
    while (n) {
      ret += (n & 1);
      n /= 10;
    }
    return ret;
  };
  auto getDigit = [&](int n) {
    int ret = (n == 0);
    while (n) {
      ret++;
      n /= 10;
    }
    return ret;
  };

  q.push({0, N});
  while (q.size()) {
    auto [fl, fr] = q.front();
    q.pop();
    fl += countOdd(fr);
    if (fr < 10) {
      m = min(m, fl);
      M = max(M, fl);
    } else if (fr < 100) {
      q.push({fl, fr % 10 + fr / 10});
    } else {
      int digit = getDigit(fr);
      for (int i = 1; i <= digit - 2; ++i) {
        for (int j = 1; i + j <= digit - 1; ++j) {
          int k = digit - i - j;

          int ttmp = fr;
          int t1 = ttmp % int(pow(10, i));
          ttmp /= int(pow(10, i));
          int t2 = ttmp % int(pow(10, j));
          int t3 = ttmp / int(pow(10, j));
          q.push({fl, t1 + t2 + t3});
        }
      }
    }
  }

  cout << m << ' ' << M << '\n';
}