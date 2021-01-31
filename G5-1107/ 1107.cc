#include <iostream>
#include <cmath>

using namespace std;


int N, M;
int NUM_OF_DIGITS = 0;
// 1, 10, 100 의 자리 -> digits[0,1,2]
int digits[6] = {};
bool isButtonBroken[10] = {};
int number = 0;
int answer = 500000;
void bfs(int digit) {
    if (digit != 0 && digit == NUM_OF_DIGITS - 1) {
        answer = min(answer, digit + abs(N - number));
    }
    if (digit == NUM_OF_DIGITS) {
        answer = min(answer, digit + abs(N - number));
    }
    if (digit == NUM_OF_DIGITS + 1) {
        // 그 다음 자리수 까지 체크해봄
        answer = min(answer, digit + abs(N - number));
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!isButtonBroken[i]) {
            number += i * ((int)pow(10, digit));
            bfs(digit + 1);
            number -= i * ((int)pow(10, digit));
        }
    }

}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int button;
        cin >> button;
        isButtonBroken[button] = true;
    }
    int x = 1;

    while (x <= 100000) {
        digits[(int)log10(x)] = (N % (10*x))/x;
        x *= 10;
    }
    NUM_OF_DIGITS = to_string(N).length();
    bfs(0);
    answer = min(answer, abs(N - 100));

    cout << answer << "\n";
}