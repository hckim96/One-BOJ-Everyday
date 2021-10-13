#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        long long N, M, k, D;
        cin >> N >> M >> k >> D;

        long long tmp = ((M - 1) * k + (N - 1) * M) * N * M / 2;

        if (tmp > D) {
            cout << "-1\n";
        } else {
            cout << D - D % tmp << '\n';
        }
    }
}