#include <iostream>

using namespace std;

int main() {

    int num;
    cin >> num;

    if (num >= 90) {
        cout << "A\n";
        return 0;
    }

    if (num >= 80) {
        cout << "B\n";
        return 0;
    }

    if (num >= 70) {
        cout << "C\n";
        return 0;
    }
    
    if (num >= 60) {
        cout << "D\n";
        return 0;
    }

    cout << "F\n";
}