#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    cin >> L;

    int r = 1;
    int M = 1234567891;
    int H = 0;

    while (L--) {
        char c;
        cin >> c;

        H = (1LL * (c - 'a' + 1) * r  + H) % M;
        r = 1LL * r * 31 % M;
    }

    cout << H << '\n';
}
