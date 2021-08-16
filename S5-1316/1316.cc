#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    int answer = 0;
    while (N--) {
        string s;
        cin >> s;

        vector<bool> check(26, false);

        bool isGroupWord = true;
        for (int i = 0; i < s.size(); ++i) {
            if (check[s[i] - 'a'] && s[i - 1] != s[i]) {
                isGroupWord = false;
                break;
            }
            check[s[i] - 'a'] = true;
        }

        answer += isGroupWord;
    }

    cout << answer << '\n';
}