#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    long long S;
    cin >> S;

    long long N = 1;

    while (N * (N + 1) / 2 <= S) {
        ++N;
    }

    cout << N - 1 << '\n';
}