#include <iostream>

using namespace std;

int calculate(int n, int k) {
    int mul, div;
    mul = div = 1;
    k = n - k < k ? n - k : k;

    int tmpk = k;
    for (int i = 0; i < tmpk; i++) {
        mul *= n--;
        div *= k--;
    }

    return mul / div;
}

int main() {
    int N, K;

    cin >> N >> K;

    cout << calculate(N, K) << "\n";
}