#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    int A, B;
    A = B = N;

    while (C--) {
        int x, y;
        cin >> x >> y;

        int up = B * min(x, A);
        int left = A * min(y, B);

        if (up >= left) {
            A = min(x, A);
        } else {
            B = min(y, B);
        }
    }

    cout << A * B << '\n';
}