#include <iostream>
#include <cmath>

using namespace std;

#define N_MAX 10000

int N;

double x[N_MAX] = {0};
double y[N_MAX] = {0};

double answer = 0;
int main() {

    cin >> N;

    int originX, originY;
    cin >> originX >> originY;

    for (int i = 1; i < N; i++) {
        int tmpX, tmpY;

        cin >> tmpX >> tmpY;

        x[i] = tmpX - originX;
        y[i] = tmpY - originY;
    }

    for (int i = 1; i < N - 1; i++) {
        answer += x[i] * y[i + 1] - x[i + 1] * y[i];
    }

    answer = abs(answer);
    answer = answer / 2;
    answer = round(answer * 10) / 10;

    // for print fractional part
    answer += 0.01;
    cout.precision(int(log10(answer)) + 2);
    cout << showpoint << answer << "\n";

    // answer += 0.01 , precision 설정 안하고 그냥 printf %.1f 로 할 수 도 있긴 함
}