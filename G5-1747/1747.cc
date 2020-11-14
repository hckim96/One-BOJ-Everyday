#include <iostream>

using namespace std;

#define CHECK_MAX 1003001

bool isPrime[CHECK_MAX + 1] = {0};
int N;

bool isPalindrome(int n) {
    string str(to_string(n));

    for (int i = 0; i < str.size() / 2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

void checkPrime() {
    fill_n(isPrime, CHECK_MAX + 1, true);
    isPrime[1] = false;
    
    for (int i = 2; i * i <= CHECK_MAX; i++) {
        if (!isPrime[i]) {
            continue;
        }

        for (int j = 2 * i; j <= CHECK_MAX; j += i) {
            isPrime[j] = false;
        }
    }
}

int main() {
    cin >> N;

    checkPrime();

    for (int i = N; i <= CHECK_MAX; i++) {
        if (isPrime[i] && isPalindrome(i)) {
            cout << i << "\n";
            return 0;
        }
    }

    return 0;
}