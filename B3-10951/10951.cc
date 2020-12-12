#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B;

    while (true) {
        cin >> A >> B;

        if (cin.eof()) {
            break;
        }
        cout << A + B << "\n";
    }
}