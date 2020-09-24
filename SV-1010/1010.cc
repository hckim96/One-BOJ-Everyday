#include <iostream>

using namespace std;
int main() {
    int T, N, M;
    int answer;

    cin >> T;

    for (int i = 0; i < T; i++){
        cin >> N;
        cin >> M;
        answer = 1;
        int n = M, r = N;
        if (r * 2 > n) r = n - r;
        answer = 1;
        for (int j = 1; j <= r; j++) {
            answer *= (n - j + 1);
            answer /= j;

        }
        cout << answer << endl;
    }
}
