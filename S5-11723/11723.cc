#include <iostream>

using namespace std;

int M;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M;

    int n = 0;
    while (M--) {
        string tmp;
        cin >> tmp;
        if (tmp == "all") {
            n = 1048575; // (1 << 20) - 1
        } else if (tmp == "empty") {
            n = 0;
        } else {
            int num;
            cin >> num;
            num--;
            if (tmp == "add") {
                n |= 1 << num;
            } else if (tmp == "remove") {
                n &= ~(1 << num);
            } else if (tmp == "check") {
                if (n & (1 << num)) {
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            } else if (tmp == "toggle") {
                n ^= 1 << num;
            }
        }
    }
}