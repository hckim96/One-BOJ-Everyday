#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;

    cin >> T;

    while (T--) {
        string tmp;
        cin >> tmp;

        int score = 0;
        int cnt = 0;

        for (auto c : tmp) {
            if (c == 'O') {
                cnt++;
                score += cnt;
            } else {
                cnt = 0;
            }
        }
        cout << score << "\n";
    }
}