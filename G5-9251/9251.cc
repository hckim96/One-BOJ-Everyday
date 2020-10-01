#include <iostream>

using namespace std;

string str1,str2;

int main() {
    cin >> str1 >> str2;

    int** lcs = new int*[str1.size()];
    for (int i = 0 ;i < str1.size(); i++) {
        lcs[i] = new int[str2.size()];
    }

    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (str1[i] == str2[j]) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 1;
                } else {
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
            } else {
                int left, up;
                if (i == 0) {
                    if (j == 0) {
                        left = 0;
                        up = 0;
                    } else {
                        up = 0;
                        left = lcs[i][j - 1];
                    }
                } else {
                    if (j == 0) {
                        left = 0;
                        up = lcs[i - 1][j];
                    } else {
                        up = lcs[i - 1][j];
                        left = lcs[i][j - 1];
                    }
                }
                lcs[i][j] = left < up ? up : left;
            }
        }
    }

    cout << lcs[str1.size() - 1][str2.size() - 1] << "\n";
    
}