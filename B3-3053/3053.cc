#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    long double R;
    cin >> R;

    cout.precision(4);
    cout << fixed;

    long double pi = 3.14159265358979;
    cout << pi * R * R << '\n';
    cout << 2 * R * R << '\n';
}