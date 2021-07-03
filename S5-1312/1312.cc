#include <iostream>

using namespace std;

int main() {
    int A, B, N;

    cin >> A >> B >> N;

    int answer;

    A = A % B;

    while (N--) {

        A *= 10;
        answer = A / B;
        A = A % B;
    }

    cout << answer << '\n';
}
