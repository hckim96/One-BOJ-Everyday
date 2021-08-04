#include <iostream>

using namespace std;

int gcd(int l, int s) {
    if (s == 0) {
        return l;
    }

    return gcd(s, l % s);
}

int lcm(int l, int s) {
    return l * s / gcd(l, s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        
        int _lcm = lcm(M, N);

        int k = x;

        while (k <= _lcm) {
            if ((k - 1) % N + 1 == y) {
                break;
            }
            k += M;
        }

        if (k <= _lcm) {
            cout << k << '\n';
        } else {
            cout << "-1\n";
        }
    }
}
