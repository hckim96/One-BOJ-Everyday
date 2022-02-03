#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, l , r;
    cin >> N >> l >> r;

    if (l > r) swap(l, r);
    int answer = 1;

    while (!(l & 1 && l + 1 == r)) {
        l = l + 1 >> 1;
        r = r + 1 >> 1;
        ++answer;
    }

    cout << answer << '\n';
}