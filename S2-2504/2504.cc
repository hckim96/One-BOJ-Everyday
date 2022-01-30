#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    string s;
    cin >> s;

    int answer = 0;
    int tmp = 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            tmp *= 2;
        } else if (s[i] == ')') {
            if (tmp % 2) {
                answer = 0;
                break;
            }
            if (i - 1 >= 0 && s[i - 1] == '(') {
                answer += tmp;
            }
            tmp /= 2;
        } else if (s[i] == '[') {
            tmp *= 3;
        } else {
            if (tmp % 3) {
                answer = 0;
                break;
            }
            if (i - 1 >= 0 && s[i - 1] == '[') {
                answer += tmp;
            }
            tmp /= 3;
        }
    }

    if (tmp != 1) answer = 0;
    cout << answer << '\n';
}