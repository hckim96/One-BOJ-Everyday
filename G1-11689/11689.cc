#include <iostream>

using namespace std;

int main() {
    long long N;
    cin >> N;

    long long answer = N;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) {
            answer -= answer / i;
            N /= i;

            while (N % i == 0) {
                N /= i;
            }
        }
    }

    if (N > 1) {
        answer -= answer / N;
    }

    cout << answer << '\n';
}
