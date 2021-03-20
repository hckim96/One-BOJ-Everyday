#include <iostream>

using namespace std;

int main() {
    int answer = 0;
    int num;
    for (int i = 0; i < 5; ++i) {
        cin >> num;
        answer += (num % 10) * (num % 10);
        answer %= 10;
    }

    cout << answer << '\n';
}