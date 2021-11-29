#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int X;
    cin >> X;

    int n = 0;

    while (n * (n + 1) / 2 < X) ++n;

    int cnt = n * (n + 1) / 2 - X;
    ++cnt;

    int r = n + 1 - cnt;
    int c = n + 1 - r;
    if (n & 1) swap(r, c);
    cout << r << "/" << c << '\n';
}