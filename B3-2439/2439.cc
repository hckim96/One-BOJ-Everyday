#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        int j = 0;
        while (j++ < N - i) {
            cout << ' ';
        }
        while (j++ <= N) {
            cout << '*';
        }
        cout << '\n';
    }
}