#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str, bomb;
    char answer[1000000];

    cin >> str >> bomb;
    int bombSize = bomb.size();
    int strSize = str.size();

    int idx = 0;
    int answerSize = 0;

    while (idx  < strSize) {
        answer[answerSize] = str[idx];
        answerSize++;

        if (answer[answerSize - 1] == bomb[bombSize - 1]) {
            bool hasBomb = true;

            if (answerSize < bombSize) {
                hasBomb = false;
            } else {
                // check bomb
                for (int j = answerSize - 2; j > answerSize - bombSize - 1 ; j--) {
                    if (answer[j] != bomb[j - answerSize + bombSize]) {
                        hasBomb = false;
                        break;
                    }
                }
            }

            if (hasBomb) {
                answerSize -= bombSize;
            }
        }
        idx++;
    }

    if (answerSize == 0) {
        cout << "FRULA\n";
    } else {
        answer[answerSize] = '\0';
        cout << answer << "\n";
    }
}