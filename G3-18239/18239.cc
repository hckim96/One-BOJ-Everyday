#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    if (N == 3) {
        cout << "NO\n";
        return 0;
    }

    int cnt = 5;
    cout << "YES\n";
    if (1 < K) --cnt, cout << "reverse " << 1 << ' ' << K << '\n';
    if (K + 1 < N) --cnt, cout << "reverse " << K + 1 << ' ' << N << '\n';
    --cnt, cout << "reverse " << 1 << ' ' << N << '\n';

    if (cnt == 3) {
        cout << "swap 1 4\n";
        cout << "swap 2 3\n";
        cout << "reverse 1 4\n";
    } else {
        while (cnt--) {
            cout << "swap 1 2\n";
        }
    }
}