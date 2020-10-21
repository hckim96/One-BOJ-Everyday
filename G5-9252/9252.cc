#include <iostream>
#include <string>
#include <stack>

using namespace std;

int LCS[1001][1001] = {0};
int main() {
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 1; i < str1.length() + 1; i++) {
        for (int j = 1; j < str2.length() + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = max(LCS[i][j - 1], LCS[i - 1][j]);
            }
        }
    }
    
    cout << LCS[str1.length()][str2.length()] << "\n";
    int i = str1.length();
    int j = str2.length();

    stack<char> s;

    while (LCS[i][j] != 0) {
        if (str1[i - 1] == str2[j - 1]) {
            s.push(str1[i - 1]);
            i--;
            j--;
        } else {
            if (LCS[i - 1][j] > LCS [i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();

    }

    cout << "\n";


}