#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        string str = to_string(N);
        int len = str.size();
        bool isPalindrome = true;
        
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i]) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}