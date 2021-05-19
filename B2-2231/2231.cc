#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int tmp = N;
    int digit = 0;
    while (tmp) {
        tmp /= 10;
        ++digit;
    }

    int start = N - digit * 9;
    if (start < 0) {
        start = 0;
    }
    
    for (int i = start; i < N; ++i) {
        int tmp = i;
        int sum = i;

        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        
        if (sum == N) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "0\n";
}
