#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        bool flag = true;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                int cnt = 0;
                while (++i < s.size()) {
                    if (s[i] == '0') {
                        ++cnt;
                    } else {
                        break;
                    }
                }

                if (cnt < 2) {
                    flag = false;
                    break;
                }

                if (i == s.size()) {
                    flag = false;
                    break;
                }

                int cnt2 = 1;
                while (++i < s.size()) {
                    if (s[i] != '1') {
                        break;
                    }
                    ++cnt2;
                }

                if (cnt2 > 1 && i + 1 < s.size() && s[i + 1] == '0') {
                    i -= 2;
                } else {
                    i -= 1;
                }
            } else {
                if (i + 1 == s.size() || s[i + 1] != '1') {
                    flag = false;
                    break;
                }
                ++i;
            }
        }

        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
