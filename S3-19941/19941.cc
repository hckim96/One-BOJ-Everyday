#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    int answer = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'H' || s[i] == ' ') continue;
        for (int k = -K; k <= K; ++k) {
            if (i + k < 0 || i + k >= s.size()) continue;
            if (s[i + k] == 'H') {
                ++answer;
                s[i + k] = ' ';
                break;
            }
        }
    }

    cout << answer << '\n';
}