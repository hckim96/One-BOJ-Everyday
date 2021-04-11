#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    double answer = 0;
    int maxNum = 0;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;

        answer += num;
        maxNum = max(maxNum, num);
    }

    cout.precision(2);
    cout << fixed << answer / N / maxNum * 100 << '\n';
}