#include <iostream>

using namespace std;

bool f(int num) {
    int cnt = 0;

    while (num && cnt != 3) {
        if (num % 10 == 6) {
            ++cnt;
        } else {
            cnt = 0;
        }
        num /= 10;
    }

    return cnt == 3;
}

int main() {
    int N;
    cin >> N;

    int cnt = 0;

    int answer = 666;
    
    while (cnt != N) {
        if (f(answer)) {
            ++cnt;
        }
        ++answer;
    }

    cout << answer - 1 << '\n';
}
