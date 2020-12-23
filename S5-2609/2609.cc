#include <iostream>

using namespace std;

int gcd(int big, int small) {
    if (small == 0) {
        return big;
    }

    return gcd(small, big % small);
}

int a, b;

int main() {
    cin >> a >> b;
    
    int big, small;
    if (a > b) {
        big = a;
        small = b;
    } else {
        big = b;
        small = a;
    }

    int _gcd = gcd(big, small);

    cout << _gcd << "\n";
    cout << a * b / _gcd << "\n";
}