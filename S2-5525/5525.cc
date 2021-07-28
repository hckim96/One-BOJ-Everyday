#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string s;
    cin >> s;

    string pattern = "I";

    for (int i = 0; i < N; ++i) {
        pattern += "OI";
    }

    vector<int> pi(2 * N + 1, 0);

    for (int i = 1, j = 0; i < pi.size(); ++i) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (pattern[i] == pattern[j]) {
            pi[i] = ++j;
        }
    }

    int answer = 0;
    for (int i = 0, j = 0; i < s.size(); ++i) {
        while (j > 0 && s[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if (s[i] == pattern[j]) {
            ++j;

            if (j == pattern.size()) {
                j = pi[j - 1];
                ++answer;
            }
        }
    }

    cout << answer << '\n';
}