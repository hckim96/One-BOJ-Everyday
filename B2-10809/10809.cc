#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> pos(26, -1);
    for (int i = 0; i < s.size(); ++i) {
        if (pos[s[i] - 'a'] == -1) {
            pos[s[i] - 'a'] = i;
        }
    }

    for (int i = 0; i < 26; ++i) {
        cout << pos[i] << ' ';
    }
    cout << '\n';
}
