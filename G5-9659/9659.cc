#include <iostream>

using namespace std;

long long N;

int main() {
    cin >> N;

    if (N % 2 == 0) {
        cout << "CY" << "\n";
    } else {
        cout << "SK" << "\n";
    }
}