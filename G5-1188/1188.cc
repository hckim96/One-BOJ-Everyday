#include <iostream>

using namespace std;

int GCD(int big, int small) {
    if (small == 0) {
        return big;
    }

    return GCD(small, big % small);
}

int N, M;
int main() {
    cin >> N >> M;
    int big, small;
    if (N > M) {
        big = N;
        small = M;
    } else {
        big = M;
        small = N;
    }

    cout << M - GCD(big, small) << "\n";
}
