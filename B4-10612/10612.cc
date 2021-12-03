#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T;
    cin >> T;

    int a, b, c;

    a = T / 300;
    T -= 300 * a;
    b = T / 60;
    T -= 60 * b;
    c = T / 10;
    T -= 10 * c;

    if (T) {
        cout << "-1\n";
    } else {
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}