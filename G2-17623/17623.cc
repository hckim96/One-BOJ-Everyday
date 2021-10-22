#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

map<char, int> m = {
    {'(', 1},
    {')', 2},
    {'{', 3},
    {'}', 4},
    {'[', 5},
    {']', 6},
};

string min_(string& s1, string s2) {
    if (s1 == "INF") {
        return s2;
    } else if (s2 == "INF") {
        return s1;
    }
    
    if (s1.size() < s2.size()) {
        return s1;
    } else if (s1.size() > s2.size()) {
        return s2;
    }

    auto it1 = s1.begin();
    auto it2 = s2.begin();

    while (it1 != s1.end()) {
        if (m[*it1] > m[*it2]) {
            return s2;
        } else if (m[*it1] < m[*it2]) {
            return s1;
        }

        ++it1;
        ++it2;        
    }

    return s1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    int T;
    cin >> T;

    vector<string> dp(1000 + 1, "INF");
    dp[0] = "";
    dp[1] = "()";
    dp[2] = "{}";
    dp[3] = "[]";
    for (int i = 4; i <= 1000; ++i) {
        for (int k = 1; k < i; ++k) {
            dp[i] = min_(dp[i], dp[k] + dp[i - k]);
        }
        if (i % 2 == 0) dp[i] = min_(dp[i], "(" + dp[i / 2] + ")");
        if (i % 3 == 0) dp[i] = min_(dp[i], "{" + dp[i / 3] + "}");
        if (i % 5 == 0) dp[i] = min_(dp[i], "[" + dp[i / 5] + "]");
    }

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
}