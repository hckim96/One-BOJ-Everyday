#include <iostream>
#include <string>

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        int len = tmp.size();

        int leftParenthesis = 0;
        bool isVPS = true;
        for (int j = 0; j < len; j++) {
            if (tmp[j] == '(') {
                leftParenthesis++;
            } else if (tmp[j] == ')') {
                if (leftParenthesis == 0) {
                    isVPS = false;
                    break;
                }
                leftParenthesis--;
            }
        }

        if (isVPS && leftParenthesis > 0) {
            isVPS = false;
        }

        if (isVPS) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

}