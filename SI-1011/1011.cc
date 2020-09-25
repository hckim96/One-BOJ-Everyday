#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y, T;

    int sqrt, d, answer;
    cin >> T;

    while (T-- > 0) {
        cin >> x >> y;
        d = y - x;
        sqrt = (int)sqrtf(d);

        if (d <= pow(sqrt, 2)) {
            answer = 2 * sqrt - 1;
        } else if (d > pow(sqrt, 2) + sqrt) {
            answer = 2 * sqrt + 1;

        } else {
            answer = 2 * sqrt;

        }
        cout << answer << endl;
    }
}