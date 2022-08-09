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

  map<string, string> m;
  m["A+"] = "4.3";
  m["A0"] = "4.0";
  m["A-"] = "3.7";
  m["B+"] = "3.3";
  m["B0"] = "3.0";
  m["B-"] = "2.7";
  m["C+"] = "2.3";
  m["C0"] = "2.0";
  m["C-"] = "1.7";
  m["D+"] = "1.3";
  m["D0"] = "1.0";
  m["D-"] = "0.7";
  m["F"] = "0.0";

  string s;
  cin >> s;
  cout << m[s];
}