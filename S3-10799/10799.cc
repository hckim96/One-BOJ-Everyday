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
    
    int cnt = 0;
    long long answer = 0;
    for (int i = 0; i < s.size(); ++i) {

        if (s[i] == '(') {
            ++cnt;
        } else if (s[i] == ')') {
            if (s[i - 1] == '(') {
                answer += cnt - 1;
            } else {
                ++answer;
            }
            --cnt;
        }
    }

    cout << answer << '\n';
}