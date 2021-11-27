#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    if (c - b <= 0) {
        cout << "-1\n";
    } else {
        cout << a / (c - b) + 1 << '\n';
    }
}