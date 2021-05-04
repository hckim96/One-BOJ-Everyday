#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s; 
    cin >> s;
    s = ' ' + s;

    vector<vector<bool> > isPalindrome(s.size(), vector<bool> (s.size(), false));

    for (int l = 0; l < s.size() - 1; ++l) {
        for (int i = 1; i < s.size(); ++i) {
            int j = i + l;
            if (j >= s.size()) {
                break;
            }

            isPalindrome[i][j] = (i == j) || (((i + 1 == j) || isPalindrome[i + 1][j - 1]) && (s[i] == s[j]));
        }
    }

    vector<int> dp(s.size(), s.size());
    dp[0] = 0;

    for (int e = 1; e < s.size(); ++e) {
        for (int s = 1; s <= e; ++s) {
            if (isPalindrome[s][e]) {
                dp[e] = min(dp[e], dp[s - 1] + 1);
            }
        }
    }

    cout << dp[s.size() - 1] << '\n';
}
