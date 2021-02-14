#include <iostream>

using namespace std;

long long f(int a, int b, int c) {
    if (b == 1) {
        return a % c;
    }
    
    long long answer =  f(a, b / 2, c);

    if (b % 2 == 0) {
        return (answer * answer) % c;
    }

    return (((answer * answer) % c) * (a % c)) % c;
}

int main() {
    int A, B, C;

    cin >> A >> B >> C;

    cout << f(A, B, C) << '\n';
}