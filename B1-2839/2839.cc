#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int x, y;

    y = N / 5;

    while (y >= 0) {
        int tmp = N - 5 * y;

        if (tmp % 3 == 0) {
            x = tmp / 3;
            break;
        }
        --y;
    }

    if (y >= 0) {
        cout << x + y << '\n';
    } else {
        cout << "-1\n";
    }
}
