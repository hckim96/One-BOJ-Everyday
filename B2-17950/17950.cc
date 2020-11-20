#include <iostream>
#include <cmath>

using namespace std;

#define H_MAX 1000000

int H, x;
long long sum;
int c[H_MAX] = {0};
int main() {
    cin >> H >> x;

    for (int i = 0; i < H; i++) {
        // i + 1 높이 에서 만들어진 스노우볼 개수
        cin >> c[i];
    }

    sum = c[H - 1] * x;

    for (int i = H - 2; i >=0; i--) {
        sum = ((sum + c[i]) * x) % (1000000007);
    }

    cout << sum << "\n";

}