#include <iostream>

using namespace std;

#define N_MAX 200000

int N, Q;

// number[i] , i + 1 th ^ i + 2 th
int xorResult[N_MAX - 1];

// 1th xor ith
int xorWith[N_MAX + 1] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++) {
        cin >> xorResult[i];
    }

    
    for (int i = 2; i <= N; i++) {
        xorWith[i] = xorWith[i - 1] ^ xorResult[i - 2];
    }
      
    int type, x, y, d;
    while (Q--) {
        cin >> type;
        if (type == 1) {
            cin >> x >> y >> d;
            if (x == y) {
                cout << d << "\n";
            } else {
                int answer = d;
                answer = answer ^ xorWith[x] ^ xorWith[y];
                cout << answer << "\n";
            }


        } else {
            cin >> x >> y;
            if (x == y) {
                cout << 0 << "\n";
            } else {
                int answer = 0;
                answer = answer ^ xorWith[x] ^ xorWith[y];
                cout << answer << "\n";
            }

        }
    }
}