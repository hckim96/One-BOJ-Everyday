#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif

  ll a, b;
  cin >> a >> b;
  function<ll(ll, ll)> f = [&](ll n1, ll n2) {
    if (n2 == 0) return n1;
    return f(n2, n1 % n2);
  };
  // ll gcd_ = gcd(a, b);
  ll gcd_ = f(a,b);
  cout << a / gcd_ * b;
}