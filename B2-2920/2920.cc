#include <iostream>
#include <string>

using namespace std;

int main() {
    int prev, next;
    string answer;

    cin >> prev;

    for (int i = 1; i < 8; i++) {
        cin >> next;

        if (prev < next) {
            if (answer == "descending") {
                answer = "mixed";
                break;
            }
            answer = "ascending";
        } else {
            if (answer == "ascending") {
                answer = "mixed";
                break;
            }
            answer = "descending";
        }
        prev = next;
    }

    cout << answer << "\n";
}