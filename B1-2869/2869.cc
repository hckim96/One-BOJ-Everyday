#include <iostream>

using namespace std;

int main() {
    int A, B, V;

    cin >> A >> B >> V;

    int tmp1 = (V - A) / (A - B);
    int tmp2 = (V - A) % (A - B);

    if (tmp2) {
        cout << tmp1 + 2 << '\n';
    } else {
        cout << tmp1 + 1 << '\n';
    }
}
