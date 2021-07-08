#include <iostream>

using namespace std;

int gcd(int l, int s) {
    if (!s) {
        return l;
    }

    return gcd(s, l % s);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n1, n2;
        cin >> n1 >> n2;

        if (n1 < n2) {
            swap(n1, n2);
        }

        int gcd_ = gcd(n1, n2);

        cout << n1 * n2 / gcd_ << '\n';
    }
}