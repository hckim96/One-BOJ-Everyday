#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int answer = 1;
    while ((answer << 1) <= N) {
        answer <<= 1;
    }
    cout << answer << '\n';
}