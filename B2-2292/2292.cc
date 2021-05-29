#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int tmp = 1;
    int i = 1;

    while (tmp < N) {
        tmp += 6 * i;
        ++i;
    }

    cout << i << '\n';
}
