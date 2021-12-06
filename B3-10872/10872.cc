#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N;
    cin >> N;

    function<int(int)> fact = [&](int n) {
        if (n == 0) {
            return 1;
        }

        return n * fact(n - 1);
    };

    cout << fact(N) << '\n';
}