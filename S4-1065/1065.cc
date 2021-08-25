#include <iostream>

using namespace std;

bool isHANSU(int x) {
    bool ret = true;
    if (x / 10 == 0) {
        return ret;
    }

    int d = x % 10 - (x / 10) % 10;
    while (x / 10) {
        if (d != x % 10 - (x / 10) % 10) {
            ret = false;
            break;
        }
        x /= 10;
    }

    return ret;
}

int main() {
    int N;
    cin >> N;

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (isHANSU(i)) {
            ++answer;
        }
    }
    cout << answer << '\n';
}
