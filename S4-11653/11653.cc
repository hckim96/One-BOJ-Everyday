#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int div = 2;

    while (N != 1) {
        if (N % div == 0) {
            N /= div;
            cout << div << '\n';
        } else {
            ++div;
        }
    }
}