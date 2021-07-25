#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int answer = 0;
    int num = 0;
    int i = 0;
    while (i != s.size() && s[i] != '+' && s[i] != '-') {
        num *= 10;
        num += s[i] - '0';
        ++i;
    }

    answer += num;

    bool flag = false;


    for (; i < s.size(); ++i) {
        if (s[i] == '+' || s[i] == '-') {
            if (flag) {
                continue;
            }

            if (s[i] == '-') {
                flag = true;
            }
        } else {
            int num = 0;
            while (i != s.size() && s[i] != '+' && s[i] != '-') {
                num *= 10;
                num += s[i] - '0';
                ++i;
            }
            --i;

            if (flag) {
                answer -= num;
            } else {
                answer += num;
            }
        }
    }

    cout << answer << '\n';
}