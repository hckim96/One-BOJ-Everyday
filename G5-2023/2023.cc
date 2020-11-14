#include <iostream>

using namespace std;

int N;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs(int number, int digitCnt) {
    if (digitCnt == N) {
        cout << number << "\n";
        return;
    }

    for (int i = 1; i < 10; i += 2) {
        if (isPrime(number * 10 + i)) {
            dfs(number * 10 + i, digitCnt + 1);
        }
    }
}

int main() {

    cin >> N;

    dfs(2, 1);
    dfs(3, 1);
    dfs(5, 1);
    dfs(7, 1);

}