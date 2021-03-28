#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;

    getline(cin, s);
    auto it = s.begin();

    int answer = 1;

    while (it != s.end()) {
        if (*it == ' ' && (it != s.begin() && it != s.end() - 1)) {
            ++answer;
        }
        ++it;
    }

    if (s.size() == 1 && s[0] == ' ') {
        --answer;
    }

    cout << answer << '\n';
}
