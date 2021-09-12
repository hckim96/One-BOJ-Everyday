#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int answer = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'c') {
            if (i + 1 != s.size() && s[i + 1] == '=' || s[i + 1] == '-') {
                ++i;
            }
        }

        if (s[i] == 'd') {
            if (i + 1 != s.size() && s[i + 1] == 'z' && i + 2 != s.size() && s[i + 2] == '=') {
                ++i;
            }

            if (i + 1 != s.size() && s[i + 1] == '-') {
                ++i;
            }
        }

        if (s[i] == 'l') {
            if (i + 1 != s.size() && s[i + 1] == 'j') {
                ++i;
            }
        }
        if (s[i] == 'n') {
            if (i + 1 != s.size() && s[i + 1] == 'j') {
                ++i;
            }
        }
        if (s[i] == 's') {
            if (i + 1 != s.size() && s[i + 1] == '=') {
                ++i;
            }
        }
        if (s[i] == 'z') {
            if (i + 1 != s.size() && s[i + 1] == '=') {
                ++i;
            }
        }

        ++answer;
    }

    cout << answer << '\n';
}