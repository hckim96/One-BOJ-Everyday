#include <iostream>

using namespace std;

int main() {
    int year;

    cin >> year;
    cout << ((!(year % 4) && year % 100) || !(year % 400) ? 1 : 0) << '\n';
}