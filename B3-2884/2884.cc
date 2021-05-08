#include <iostream>

using namespace std;

int main() {
    int H, M;
    cin >> H >> M;
    int total = 60 * H + M;
    total -= 45;

    if (total < 0) {
        total += 60 * 24;
    }
    H = total / 60;
    M = total % 60;

    cout << H << ' ' << M << '\n';
}
