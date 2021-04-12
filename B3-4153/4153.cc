#include <iostream>

using namespace std;

int main() {
    long long a, b, c;

    while (true) {
        cin >> a >> b >> c;
        if (!a && !b && !c) {
            break;
        }

        long long maxNum = 0;
        maxNum = max(a, max(b, c));

        if (maxNum * maxNum * 2 == a * a + b * b + c * c) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
}