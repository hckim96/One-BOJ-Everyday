#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K, Q;
    cin >> N >> K >> Q;

    long long minQ = 0;
    long long diff = 0;
    bool flag = true;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < K; ++j) {
            int c;
            cin >> c;

            if (i == 1 && c != 1) flag = false;
            diff += (c - i + N) % N;
        }
    }

    minQ = diff / N + flag;
    cout << (minQ <= Q) << '\n';
}