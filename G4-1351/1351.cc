#include <iostream>
#include <map>

using namespace std;

#define N_MAX 1e12
int P, Q;
long long N;

map<long long, long long> m;

long long f(long long n) {
  
  if (m.find(n) != m.end()) {
    return m[n];
  }

  return m[n] = f(n / P) + f (n / Q);
}

int main() {

  cin >> N >> P >> Q;
  m[0] = 1;
  cout << f(N) << "\n";
}
