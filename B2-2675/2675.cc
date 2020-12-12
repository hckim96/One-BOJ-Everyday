#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    int R;
    string S;

    cin >> T;

    while (T--) {
        cin >> R >> S;
        for (auto c : S) {
            for (int i = 0; i < R; i++) {
                cout << c;
            }
        }
        cout << "\n";
    }
}