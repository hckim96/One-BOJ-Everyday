#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int twoCnt = 0;
    int fiveCnt = 0;

    for (int i = 1; i <= N; ++i) {
        int tmp = i;
        while (tmp % 2 == 0) {
            ++twoCnt;
            tmp /= 2;
        }

        while (tmp % 5 == 0) {
            ++fiveCnt;
            tmp /= 5;
        }
    }

    cout << min(twoCnt, fiveCnt) << '\n';
}
