#include <iostream>

using namespace std;

int x[3] = {0};
int y[3] = {0};

int main() {

    for (int i = 0; i < 3; i++) {
        cin >> x[i] >> y[i];
    }
    
    int doubleS = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);

    if (doubleS > 0) {
        cout << 1 << "\n";
    } else if (doubleS < 0) {
        cout << -1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}
