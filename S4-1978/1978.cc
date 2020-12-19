#include <iostream>

using namespace std;

#define NUM_MAX 1000

bool isPrime[NUM_MAX + 1];
int N;

int main() {
    cin >> N;
    fill_n(isPrime, NUM_MAX + 1, true);

    isPrime[1] = false;

    for (int i = 2; i * i <= NUM_MAX; i++) {
        if (!isPrime[i]) {
            continue;
        }

        for (int j = 2 * i; j <= NUM_MAX; j += i) {
            isPrime[j] = false;
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (isPrime[num]) {
            answer++;
        }
    }
    cout << answer << "\n";
}